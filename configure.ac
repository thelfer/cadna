#                                               -*- Autoconf -*-	
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(CADNA,3.0-dev, cadna-team@lip6.fr)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([-Wall])

#disable static library generation by default
AC_ENABLE_STATIC(no)

AN_MAKEVAR([AR], [AC_PROG_AR])
AN_PROGRAM([ar], [AC_PROG_AR])
AC_DEFUN([AC_PROG_AR], [AC_CHECK_TOOL(AR, ar, :)])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])
AM_PROG_AR
AM_PROG_AS

AC_PROG_INSTALL

AC_PROG_RANLIB
AC_PROG_MAKE_SET

# Libtool specific stuff
AC_LIBTOOL_WIN32_DLL
AC_LIBTOOL_DLOPEN
AC_PROG_LIBTOOL
AC_SUBST(INCLTDL)
AC_SUBST(LIBLTDL)
AC_SUBST(LIBTOOL_DEPS)

#check for fenv.h
AC_CHECK_HEADER([fenv.h],,
[AC_MSG_ERROR([cannot find fenv.h])])

AC_MSG_CHECKING([if 64bit support is requested])
AC_ARG_ENABLE(64bit,[  --enable-64bit          enable 64bit support (where applicable)],architecture="64",architecture="32")
AC_MSG_RESULT($architecture)

AC_CHECK_HEADERS(math.h,,
[AC_MSG_ERROR([cannot find math.h])])

HAVE_LIBM=no
AC_CHECK_LIB(m, acos,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m, acosf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,acosh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,acoshf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,asin,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,asinf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,asinh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,asinhf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,atan,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,atan2,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,atan2f,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,atanf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,atanh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,atanhf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,cbrt,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,cbrtf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,cos,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,cosf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,cosh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,coshf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,exp,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,exp2,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,exp2f,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,expf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,expm1,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,expm1f,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,fmax,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,fmaxf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,fmin,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,fminf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,hypot,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,hypotf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,log,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,log10,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,log10f,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,log1p,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,log1pf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,log2,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,log2f,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,logb,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,logbf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,logf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,pow,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,powf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,sin,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,sinf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,sinh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,sinhf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,sqrt,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,sqrtf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,tan,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,tanf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,tanh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,tanhf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
 AC_CHECK_LIB(m,tanf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....
)))
 AC_CHECK_LIB(m,tanh,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
 AC_CHECK_LIB(m,tanhf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (powf, cosf, expf, ....)))
AC_CHECK_LIB(m,frexp,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,frexpf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (frexpf, ....)))
AC_CHECK_LIB(m,ldexp,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,ldexpf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (ldexpf, ....)))
AC_CHECK_LIB(m,fmod,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,fmodf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (fmodf, ....)))

AC_CHECK_LIB(m,modf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm))
AC_CHECK_LIB(m,modf,[HAVE_LIBM=ok],AC_MSG_ERROR(You need libm with functions on float (fmodf, ....)))

#,[AC_DEFINE(HAVE_LOG2)],[AC_MSG_ERROR([cannot find log2 function])])

AC_CONFIG_FILES([
	Makefile
	cmake/Makefile
	cmake/modules/Makefile
	include/Makefile
	src/Makefile
	tests/Makefile
	])

AC_CANONICAL_HOST

__cadna_compiler_problem=1	


  echo "configure.ac   $host"
case "$host" in

*i686-pc-linux-gnu*)	
  echo "configure.ac   *i686-pc-linux-gnu*)"
	if test $architecture = "64" ; then
	AC_MSG_ERROR("64bit implementation is not possible on 32bit system")
	fi;	
      case "$CXX" in
          *g++*)
		CADNA_MATH_FILE=src/cmath_gnu.cxx
 	      _asm_file_orig=src/rnd_x86_00_32.s
	      __cadna_compiler_problem=0
              ;;
      esac
    ;;


*i686-pc-mingw32*)	
  echo "configure.ac   *i686-pc-mingw32*)"
	if test $architecture = "64" ; then
	AC_MSG_ERROR("64bit implementation is not possible on 32bit system")
	fi;	
      case "$CXX" in
          *g++*)
		CADNA_MATH_FILE=src/cmath_gnu.cxx
 	      _asm_file_orig=src/rnd_x86_11_32.s
	      __cadna_compiler_problem=0
              ;;
      esac
    ;;


  *i686-pc-cygwin*)
  echo "configure.ac   *i686-pc-cygwin*)"	
	if test $architecture = "64" ; then
	AC_MSG_ERROR("64bit implementation is not possible on 32bit system")
	fi;	
      case "$CXX" in
          *g++*)
		CADNA_MATH_FILE=src/cmath_gnu.cxx
 	      _asm_file_orig=src/rnd_x86_10_32.s
	      __cadna_compiler_problem=0
              ;;
      esac
    ;;


  *powerpc-ibm-aix*)
      echo "configure.ac   *powerpc-ibm-aix*)   "     	
      case "$CXX" in
          g++ )
 	      CADNA_MATH_FILE=src/cmath_gnu.cxx	 
	      _asm_file_orig=src/rnd_ppc_aix.s
	      __cadna_compiler_problem=0
	      ;;
          *xlc*)
 	      CADNA_MATH_FILE=src/cmath_other.cxx
	      _asm_file_orig=src/rnd_ppc_aix.s
	      __cadna_compiler_problem=0
	      ;;
      esac
    ;;

  *ia64-hp-hpux11*)
      echo "configure.ac   *ia64-hp-hpux11*) "     	
	if test $architecture = "32" ; then
		AC_MSG_WARN("----------------------------------------------------")		
		AC_MSG_WARN("32bit implementation is not possible on 64bit system")		
		AC_MSG_WARN("64bit implementation is forced")
		AC_MSG_WARN("----------------------------------------------------")		
		architecture=64;
	fi;		    
      case "$CXX" in
          *g++*  )
              CADNA_MATH_FILE=src/cmath_gnu.cxx 
	      _asm_file_orig=src/rnd_ia64.s
	      __cadna_compiler_problem=0
              ;;
      esac
    ;; 	


#    *sparc-sun-solaris2.9*)
    *sparc-sun-solaris2.*)
      echo "configure.ac     *sparc-sun-solaris2.*)" 	
	if test $architecture = "32" ; then
		AC_MSG_WARN("----------------------------------------------------")		
		AC_MSG_WARN("32bit implementation is not possible on 64bit system")		
		AC_MSG_WARN("64bit implementation is forced")
		AC_MSG_WARN("----------------------------------------------------")		
		architecture=64;
	fi;		    
      case "$CXX" in
          *g++*)
              CADNA_MATH_FILE=src/cmath_gnu.cxx 
	      _asm_file_orig=src/rnd_sun.s
	      __cadna_compiler_problem=0
	      ;;
      esac
    ;;


 i386-apple-darwin9.*)
      echo "configure.ac  i386-apple-darwin9.*)"	
      case "$CXX" in
          *g++*)
  	      CADNA_MATH_FILE=src/cmath_gnu.cxx 
	      _asm_file_orig=src/rnd_x86_10_$architecture.s
	      __cadna_compiler_problem=0
	      ;;
      esac
    ;;

 i386-apple-darwin10.* | i386-apple-darwin11.* |  i386-apple-darwin12.*)		
      echo "configure.ac  i386-apple-darwin10.* ou 11)"	
      case "$CXX" in
	          *g++*)
 	     CADNA_MATH_FILE=src/cmath_gnu.cxx  
	     if test $architecture = "32" ; then
             	_asm_file_orig=src/rnd_X86_10_32.s ; 	  
	     else	 
                _asm_file_orig=src/rnd_x86mac_10_64.s ; 	  
	     fi;
	       
	      __cadna_compiler_problem=0
	      ;;
          *gcc-mp*)
 	     CADNA_MATH_FILE=src/cmath_gnu.cxx  
	     if test $architecture = "32" ; then
             	_asm_file_orig=src/rnd_X86_10_32.s ; 	  
	     else	 
                _asm_file_orig=src/rnd_x86mac_10_64.s ; 	  
	     fi;
	       
	      __cadna_compiler_problem=0
	      ;;
      esac
    ;;

 x86_64-apple-darwin13.*  )
 	if test $architecture = "32" ; then
		AC_MSG_WARN("----------------------------------------------------")		
		AC_MSG_WARN("32bit implementation is not possible on 64bit system")		
		AC_MSG_WARN("64bit implementation is forced")
		AC_MSG_WARN("----------------------------------------------------")		
		architecture=64;
	fi;		    
 
          case "$CXX" in    
	  *g++*)
 	     CADNA_MATH_FILE=src/cmath_gnu.cxx  
	     _asm_file_orig=src/rnd_x86mac_10_64.s ; 	  
	      __cadna_compiler_problem=0
	      ;;
          *gcc-mp*)
 	     CADNA_MATH_FILE=src/cmath_gnu.cxx  
             _asm_file_orig=src/rnd_x86mac_10_64.s ; 	  
	     __cadna_compiler_problem=0
	  ;;
      esac;
      ;;



  *x86_64*)
      echo "configure.ac   *x86_64*)  "     	
	if test $architecture = "32" ; then
		AC_MSG_WARN("----------------------------------------------------")		
		AC_MSG_WARN("32bit implementation is not possible on 64bit system")		
		AC_MSG_WARN("64bit implementation is forced")
		AC_MSG_WARN("----------------------------------------------------")		
		architecture=64;
	fi;		    


       case "$CXX" in
          *g++*)
	      CADNA_MATH_FILE=src/cmath_gnu.cxx 
	      _asm_file_orig=src/rnd_x86_00_$architecture.s
	      __cadna_compiler_problem=0
	      ;;
          icpc | icc) 
              CADNA_MATH_FILE=src/cmath_other.cxx
	      _asm_file_orig=src/rnd_x86_00_$architecture.s
	      __cadna_compiler_problem=0
              ;;
      esac;
    ;;
esac

echo "configure.ac $host $CXX $__cadna_compiler_problem"

if test $__cadna_compiler_problem -eq 0 ; then
   AC_CONFIG_LINKS([src/rounding.s:$_asm_file_orig])
else
       echo "--------------------------------------------------------"
       echo "The assembler file  does not correspond to the compiler."
       echo "Please send an email to $PACKAGE_BUGREPORT  with"
       echo "- the OS name : $host"
       echo "- the C compiler : $CXX"  	
       echo "The cadna Team will contact you back." 	
       echo "--------------------------------------------------------"
       exit 1
fi;


CXXFLAGS=""
CFLAGS="-g -O0  -m$architecture" 
CPPFLAGS="$CPPFLAGS -m$architecture" 	 
LDFLAGS="$LDFLAGS -m$architecture" 	 
CCASFLAGS="$CCASFLAGS -m$architecture" 
ASFLAGS="$ASFLAGS -m$architecture" 

AC_CONFIG_LINKS([src/cmath_specific.cxx:$CADNA_MATH_FILE])

AC_OUTPUT
