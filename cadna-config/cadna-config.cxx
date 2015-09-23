/*!
 * \file   src/CADNAConfig/cadna-config.cxx
 * \brief  
 * \author Helfer Thomas
 * \date   27 août 2007
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of CADNA. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include<map>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stdexcept>

#include"cadna/macros.hxx"
#include"cadna-config.hxx"

#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include<windows.h>
#endif

#ifndef COMPILER_FLAGS
#define COMPILER_FLAGS ""
#endif
#ifndef COMPILER_CXXFLAGS
#define COMPILER_CXXFLAGS ""
#endif
#ifndef OPTIMISATION_FLAGS0
#define OPTIMISATION_FLAGS0 ""
#endif
#ifndef OPTIMISATION_FLAGS
#define OPTIMISATION_FLAGS ""
#endif
#ifndef OPTIMISATION_FLAGS2
#define OPTIMISATION_FLAGS2 ""
#endif
#ifndef COMPILER_WARNINGS
#define COMPILER_WARNINGS ""
#endif

typedef void (*FuncPtr)(void);
typedef std::map<std::string,std::pair<FuncPtr,std::string> > CallBacksContainer;

static std::string
handleSpace(const std::string& p)
{
  using namespace std;
  if(find(p.begin(),p.end(),' ')!=p.end()){
#if defined _WIN32 || defined _WIN64
    string msg("cadna-config handleSpace: "
	       "path to CADNA shall not contain space as "
	       "MinGW can't handle it (Found '"+p+"'). "
	       "Please change CADNA installation directory");
    throw(runtime_error(msg));
#endif
    return '"'+p+'"';
  }
  return p;
}

static std::string
getCADNAHOME(void);

static std::string
libDir(void);

static std::string
includeDir(void);

static void
registerCallBack(const std::string&,
		 const FuncPtr&,
		 const std::string&);

static void
treatCompilerFlags(void);

static void
treatWarnings(void);

static void
treatOFlags0(void);

static void
treatOFlags(void);

static void
treatOFlags2(void);

static void
treatIncludes(void);

static void
treatLibs(void);

static void
listOptions(std::ostream&);

CADNA_NORETURN static void
treatUnknownOption(const std::string&);

CADNA_NORETURN static void
treatHelp(void);

CADNA_NORETURN static void
treatLicences(void);

static CallBacksContainer callBacksContainer;
static bool compilerflags   = false;
static bool oflags0         = false;
static bool oflags          = false;
static bool oflags2         = false;
static bool warnings        = false;
static bool incs            = false;
static bool libs            = false;

#if defined _WIN32 || defined _WIN64
static bool
getValueInRegistry(std::string &value)
{
  using namespace std;
  HKEY  hKey;
  char  szBuffer[512];
  DWORD dwBufferSize = sizeof(szBuffer);
  LONG  nError;
  LONG  lRes = RegOpenKeyEx(HKEY_CLASSES_ROOT,"CADNAHOME-" VERSION,0,KEY_READ,&hKey);
  if(ERROR_SUCCESS != lRes){
    return false;
  }
  nError = RegQueryValueEx(hKey,"",nullptr,nullptr,
			   reinterpret_cast<LPBYTE>(szBuffer),
			   &dwBufferSize);
  RegCloseKey(hKey);
  if (ERROR_SUCCESS == nError){
    value = szBuffer;
    return true;
  }
  return false;
}
#endif

static std::string
getCADNAHOME(void)
{
  using namespace std;
#if defined _WIN32 || defined _WIN64
  // check in the registry (installation through NSIS)
  string rpath;
  if(getValueInRegistry(rpath)){
    return handleSpace(rpath);
  }
#endif

  const char * const path = getenv("CADNAHOME");
  if(path!=nullptr){
    return handleSpace(path);
  }

#if defined _WIN32 || defined _WIN64
  string msg("cadna-config getCADNAHOME: "
	     "no CADNAHOME registry key defined and no TFEHOME "
	     "environment variable defined");
  throw(runtime_error(msg));
#endif
  return "";
}

static std::string
libDir(void)
{
  using namespace std;
  const string prefix(PREFIXDIR);
  const string execPrefix(EXECPREFIXDIR);
  string lib(LIBDIR);
#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
  const string ldir("/bin");
#else 
#ifdef LIB_SUFFIX
  const string ldir("/lib"LIB_SUFFIX);
#else
  const string ldir("/lib");
#endif
#endif
  const auto& th = getCADNAHOME();
  if(!th.empty()){
    return th+ldir;
  }
  if(lib.substr(0,14)=="${exec_prefix}"){
    if(execPrefix=="${prefix}"){
      lib = prefix+ldir;
    } else {
      lib = execPrefix+ldir;
    }
  }
  return handleSpace(lib);
} // end of libDir

static std::string
includeDir(void)
{
  using namespace std;
  const string prefix(PREFIXDIR);
  string inc(INCLUDEDIR);
  const auto& th = getCADNAHOME();
  if(!th.empty()){
    return th+"/include";
  } else {
    if(inc.substr(0,9)=="${prefix}"){
      inc = handleSpace(prefix + "/include");
    }
  }
  return inc;
} // end of libDir

static void
registerCallBack(const std::string& key,
		 const FuncPtr& f,
		 const std::string& description)
{
  callBacksContainer.insert({key,std::make_pair(f,description)});
} // end of registerNewCallBack

static void
treatCompilerFlags(void)
{
  compilerflags = true;
} // end of treatCompilerFlags

static void
treatWarnings(void){
  warnings = true;
}

static void
treatOFlags0(void)
{
  oflags0 = true;
} // end of treatOFlags

static void
treatOFlags(void)
{
  oflags0 = true;
  oflags  = true;
} // end of treatOFlags

static void
treatOFlags2(void)
{
  oflags2 = true;
} // end of treatOFlags2

static void
treatIncludes(void)
{
  incs = true;
} // end of treatIncludes


static void
treatLibs(void)
{
  libs = true;
} // end of treatLibs

static void
listOptions(std::ostream& os)
{
  os << "Valid options are : " << std::endl;
  for(const auto& c : callBacksContainer){ 
    auto options = c.first;
    if(options.size()<=18){
      options.insert(options.size(),18-options.size(),' ');
    }
    os << options << " : " << c.second.second << std::endl;
  }
} // end of listOptions

CADNA_NORETURN static void
treatVersion(void)
{
  std::cout << "cadna-config " << VERSION << std::endl;
  ::exit(EXIT_SUCCESS);
} // end of treatHelp

CADNA_NORETURN static void
treatHelp(void)
{
  std::cout << "usage : cadna-config [options]" << std::endl;
  listOptions(std::cout);
  ::exit(EXIT_SUCCESS);
} // end of treatHelp

CADNA_NORETURN static void
treatUnknownOption(const std::string& o)
{
  std::cerr << "unknown option " << o << std::endl;
  listOptions(std::cerr);
  ::exit(EXIT_FAILURE);
} // end of treatUnknownOption

CADNA_NORETURN static void
treatLicences(void)
{
  ::exit(EXIT_SUCCESS);
} // end of treatLicences

/* coverity [UNCAUGHT_EXCEPT]*/
int main(const int argc,
	 const char *const *const argv)
{
#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
  try{
#endif /* __CYGWIN__ */

  registerCallBack("--compiler-flags",&treatCompilerFlags,
		   "return cadna recommended compiler flags.");
  registerCallBack("--oflags0",&treatOFlags0,
		   "return cadna recommended optimisation flags "
		   "without architecture specific flags.");
  registerCallBack("--oflags",&treatOFlags,
		   "return cadna recommended optimisation flags "
		   "with architecture specific flags.");
  registerCallBack("--oflags2",&treatOFlags2,"return some aggressive "
		   "optimisation flags, possibly at the expense of "
		   "numerical precision. This shall be added "
		   "to `--oflags` results.");
  registerCallBack("--warnings",&treatWarnings,
		   "return cadna recommended warnings.");
  registerCallBack("--includes",&treatIncludes,
		   "return cadna include path.");
  registerCallBack("--libs",&treatLibs,"return linking flags.");
  registerCallBack("--help",&treatHelp,"print this help message.");
  registerCallBack("--version",&treatVersion,
		   "print cadna version.");
  registerCallBack("--licence",&treatLicences,"print cadna licences.");
  for(auto p2=argv+1;p2!=argv+argc;++p2){
    const auto p = callBacksContainer.find(*p2);
    if(p==callBacksContainer.end()){
      treatUnknownOption(*p2);
    }
    (*(p->second.first))();
  }

  if(incs){
    std::cout << "-I" << includeDir() << " ";
  }

  if(libs){
    std::cout << "-L" << libDir() << " -lcadna_cxx ";
  }

  if(compilerflags){
    std::cout << COMPILER_FLAGS << " " << COMPILER_CXXFLAGS << " ";
  }

  if(oflags0){
    std::cout << OPTIMISATION_FLAGS0 << " ";
  }

  if(oflags){
    std::cout << OPTIMISATION_FLAGS << " ";
  }

  if(oflags2){
    std::cout << OPTIMISATION_FLAGS2 << " ";
  }

  if(warnings){
    std::cout << COMPILER_WARNINGS << " ";
  }

  std::cout << std::endl;

#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
  }
  catch(exception& e){
    MessageBox(nullptr,e.what(),
	       "mfront",0);
    return EXIT_FAILURE;
  }
  catch(...){
    return EXIT_FAILURE;
  }
#endif /* __CYGWIN__ */

  return EXIT_SUCCESS;
}
