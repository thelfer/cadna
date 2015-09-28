/*!
 * \file   backtrace.cxx
 * \brief
 * \author THOMAS HELFER
 * \date   27 sept. 2015
 */

#include"cadna/backtrace.hxx"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include<windows.h>
#else /* _WIN32 */
#if (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__)
#include<execinfo.h>
#include<cxxabi.h>
#include<memory>
#else /* (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__) */
#ifdef CADNA_HAVE_LIBUNWIND
#define UNW_LOCAL_ONLY
#include <libunwind.h>
#ifdef __clang__
#include<cxxabi.h>
#endif
#endif /* CADNA_HAVE_LIBUNWIND */
#endif /* (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__) */
#endif /* _WIN32 */

namespace cadna{

  backtrace_node::backtrace_node() = default;
  backtrace_node::backtrace_node(backtrace_node&&) = default;
  backtrace_node::backtrace_node(const backtrace_node&) = default;
  backtrace_node& backtrace_node::operator=(backtrace_node&&) = default;
  backtrace_node& backtrace_node::operator=(const backtrace_node&) = default;

  backtrace_node::backtrace_node(std::string l,
				 std::string f,
				 std::string o)
    : library(l),
      function(f),
      offset(o)
  {}

#ifdef _WIN32
  // https://msdn.microsoft.com/en-us/library/windows/desktop/bb204633(v=vs.85).aspx
#ifdef _WIN64
  static std::vector<backtrace_node>
  backtrace_win32(void){
    // typedef USHORT (WINAPI *CaptureStackBackTraceType)(__in ULONG, __in ULONG, __out PVOID*, __out_opt PULONG);
    // auto r = std::vector<backtrace_node>{};
    // CaptureStackBackTraceType func =
    //   static_cast<CaptureStackBackTraceType>(GetProcAddress(LoadLibrary(L"kernel32.dll"), "RtlCaptureStackBackTrace"));
    // if(func == nullptr)
    //   return {}; // WOE 29.SEP.2010
    // // Quote from Microsoft Documentation:
    // // ## Windows Server 2003 and Windows XP:
    // // ## The sum of the FramesToSkip and FramesToCapture parameters must be less than 63.
    // const int kMaxCallers = 62;
    // void *callers_stack[ kMaxCallers ];
    // auto process = GetCurrentProcess();
    // SymInitialize( process, nullptr, TRUE );
    // const auto frames  = (func)(0,kMaxCallers,callers_stack,nullptr);
    // auto symbol = static_cast<SYMBOL_INFO*>(calloc(sizeof(SYMBOL_INFO)+256*sizeof(char),1));
    // if(symbol==nullptr){
    //   return {};
    // }
    // try{
    //   symbol->MaxNameLen   = 255;
    //   symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    //   for(unsigned int i = 1;  i < frames;  i++ ){
    // 	SymFromAddr( process, ( DWORD64 )( callers_stack[ i ] ), 0, symbol );
    // 	r.emplace_back("",symbol->Name,"0x"+to_string(symbol->Address));
    //   }
    // } catch(...){
    //   free(symbol);
    //   throw();
    // }
    // free(symbol);
    // return r;
    return {};
  } // end of backtrace_win32
#else /* _WIN64 */
  static std::vector<backtrace_node>
  backtrace_win32(void){
    // auto r = std::vector<backtrace_node>{};
    // void         * stack[ 100 ];
    // auto process = GetCurrentProcess();
    // SymInitialize( process,nullptr,TRUE);
    // auto frames = CaptureStackBackTrace(0,100,stack,nullptr);
    // auto symbol = static_cast<SYMBOL_INFO>(calloc(sizeof(SYMBOL_INFO)+256*sizeof(char),1));
    // symbol->MaxNameLen   = 255;
    // symbol->SizeOfStruct = sizeof( SYMBOL_INFO );
    // try{
    //   for(unsigned int i = 1; i < frames; i++){
    // 	SymFromAddr(process,static_cast<DWORD64>(stack[i]),0,symbol);
    // 	r.emplace_back("",symbol->Name,"0x"+to_string(symbol->Address));
    //   }
    // } catch(...){
    //   free(symbol);
    //   throw;
    // }
    // free(symbol);
    // return r;
    return {};
  } // end of backtrace_win32
#endif /* _WIN64 */
#else /* _WIN32 */
#if (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__)
  /*!
   * \return the backtrace using the libstdc++ bactrace function
   * \see https://panthema.net/2008/0901-stacktrace-demangled/
   */
  static std::vector<backtrace_node>
  backtrace_libstdcxx(void){
     constexpr const int max_frames = 63;
     auto r = std::vector<backtrace_node>{};
    // storage array for stack trace address data
    void* addrlist[max_frames+1];
    // retrieve current stack addresses
    const int addrlen = ::backtrace(addrlist, sizeof(addrlist) / sizeof(void*));
    if (addrlen == 0) {
      // empty, possibly corrupt
      return {};
    }
    // resolve addresses into strings containing "filename(function+address)",
    // this array must be free()-ed
    std::unique_ptr<char*,void(*)(void*)>
      symbollist(::backtrace_symbols(addrlist, addrlen),&std::free);
    // allocate string which will be filled with the demangled function name
    size_t funcnamesize = 256;
    char* funcname = (char*) std::malloc(funcnamesize);
    try{
      // iterate over the returned symbol lines. skip the first, it is the
      // address of this function.
      for (int i = 1; i < addrlen;++i){
	char *begin_name = nullptr;
	char *begin_offset = nullptr;
	char *end_offset = nullptr;
	// find parentheses and +address offset surrounding the mangled name:
	// ./module(function+0x15c) [0x8048a6d]
	for (char *p = symbollist.get()[i]; *p; ++p){
	  if (*p == '('){
	    begin_name = p;
	  } else if (*p == '+'){
	    begin_offset = p;
	  } else if (*p == ')' && begin_offset){
	    end_offset = p;
	    break;
	  }
	}
	if (begin_name && begin_offset && end_offset
	    && begin_name < begin_offset){
	  *begin_name++ = '\0';
	  *begin_offset++ = '\0';
	  *end_offset = '\0';
	  // mangled name is now in [begin_name, begin_offset) and caller
	  // offset in [begin_offset, end_offset). now apply
	  // __cxa_demangle():
	  int status;
	  char* ret = abi::__cxa_demangle(begin_name,funcname,
					  &funcnamesize, &status);
	  if (status == 0) {
	    funcname = ret; // use possibly realloc()-ed string
	    r.emplace_back(symbollist.get()[i], funcname, begin_offset);
	  } else {
	    // demangling failed. Output function name as a C function with
	    // no arguments.
	    r.emplace_back(symbollist.get()[i],begin_name, begin_offset);
	  }
	} else {
	  // couldn't parse the line? print the whole line.
	  r.emplace_back(symbollist.get()[i],"","");
	}
      }
    } catch(...){
      std::free(funcname);
      throw;
    }
    std::free(funcname);
    return r;
  } // end of backtrace_libstdcxx
#elif (defined CADNA_HAVE_LIBUNWIND)
  /*!
   * \return the backtrace using libunwind
   * \see https://gist.github.com/banthar/1343977
   */
  static std::vector<backtrace_node>
  backtrace_unwind(void){
    constexpr const size_t ns = 128;
    auto r = std::vector<backtrace_node>{};
    auto n = std::vector<char>{};
    n.resize(ns);
    unw_context_t uc;
    unw_getcontext(&uc);
    unw_cursor_t cursor;
    unw_init_local(&cursor, &uc);
    int skip = 1;
    while(unw_step(&cursor)>0){
      unw_word_t offset;
      if(skip<=0){
	if(unw_get_proc_name(&cursor,&n[0],ns,&offset)==0){
#ifdef __clang__
	  // TODO: call cxx abi to demangle the name
	  r.emplace_back("",&n[0],"");
#else
	  r.emplace_back("",&n[0],"");
#endif
	} else {
	  r.emplace_back("","<unknown function name>","");
	}
      }
      skip--;
    }
    return r;
  } // end of backtrace_unwind
#endif /* CADNA_HAVE_LIBUNWIND */
#endif /* _WIN32 */

  std::vector<backtrace_node>
  backtrace(void){
#ifdef _WIN32
    return backtrace_win32();
#else /* _WIN32 */
#if (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__)
    return backtrace_libstdcxx();
#elif (defined CADNA_HAVE_LIBUNWIND)
    return backtrace_unwind();
#else /* default (do nothing) */
    return {};
#endif /* (defined __GNUC__) && (!defined __INTEL_COMPILER) && (!defined __clang__) */
#endif /* _WIN32 */
  } // end of backtrace

} // end of namespace cadna
