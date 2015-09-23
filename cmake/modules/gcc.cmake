cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wno-conversion")
include(cmake/modules/common-compiler-flags.cmake)

set(OPTIMISATION_FLAGS "-O3 -DNDEBUG ${OPTIMISATION_FLAGS}")

cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wdisabled-optimization")
if(NOT i586-mingw32msvc_COMPILER)
  cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility=hidden")
  cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility-inlines-hidden")
endif(NOT i586-mingw32msvc_COMPILER)

cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "march=native")

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8 )
  # 32 bits machines.
  # using sse and sse2 instructions rather than the
  # i387 FPU du to numerical instabilities
  cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "mfpmath=sse")
  cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "msse")
  cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "msse2")
endif(NOT CMAKE_SIZEOF_VOID_P EQUAL 8 )

if(WIN32)
  if (CMAKE_SIZEOF_VOID_P EQUAL 8 )
    # 64 bits machines
    cadna_enable_cxx_compiler_flag(COMPILER_FLAGS "m64")
  else(CMAKE_SIZEOF_VOID_P EQUAL 4 )
    # 32 bits machines
    cadna_enable_cxx_compiler_flag(COMPILER_FLAGS "m32")
  endif(CMAKE_SIZEOF_VOID_P EQUAL 8 )
endif(WIN32)

cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS2 "ffast-math")

option(enable-sanitize-options "enable various gcc sanitize options (undefined, address,...)" OFF)

SET(CMAKE_CXX_FLAGS_DEBUG "-g" CACHE STRING
    "Flags used by the C++ compiler during debug builds."
    FORCE)
SET(CMAKE_C_FLAGS_DEBUG "-g" CACHE STRING
    "Flags used by the C compiler during debug builds."
    FORCE)

# coverage
SET(CMAKE_CXX_FLAGS_COVERAGE "-O0 -g -DNDEBUG -fprofile-arcs -ftest-coverage" CACHE STRING
    "Flags used by the C++ compiler during builds with tests coverage checks."
    FORCE)
SET(CMAKE_C_FLAGS_COVERAGE "-O0 -g -DNDEBUG -fprofile-arcs -ftest-coverage" CACHE STRING
    "Flags used by the C compiler during builds with tests coverage checks."
    FORCE)
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
  "-fprofile-arcs -ftest-coverage -lgcov")
set(CMAKE_MODULE_LINKER_FLAGS_COVERAGE
  "-fprofile-arcs -ftest-coverage -lgcov")
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
  "-fprofile-arcs -ftest-coverage -lgcov")
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_COVERAGE
  CMAKE_C_FLAGS_COVERAGE
  CMAKE_EXE_LINKER_FLAGS_COVERAGE
  CMAKE_MODULE_LINKER_FLAGS_COVERAGE
  CMAKE_SHARED_LINKER_FLAGS_COVERAGE)

# profiling
SET(CMAKE_CXX_FLAGS_PROFILING "-pg" CACHE STRING
    "Flags used by the C++ compiler during profiled builds."
    FORCE)
SET(CMAKE_C_FLAGS_PROFILING "-pg" CACHE STRING
    "Flags used by the C compiler during profiled builds."
    FORCE)
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_PROFILING
  CMAKE_C_FLAGS_PROFILING)

if(enable-sanitize-options)
  cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "fsanitize=undefined")
  cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "fsanitize=address")
  cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "fno-omit-frame-pointer")
endif(enable-sanitize-options)

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.7)
  message(FATAL_ERROR "CADNA C++11 support is only available for gcc version >= 4.7")
endif(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.7)
set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -std=c++11")
set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -frounding-math")
