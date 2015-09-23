cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Weverything")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wno-padded")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wno-documentation")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wno-exit-time-destructors")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wno-global-constructors")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wrange-loop-analysis")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wmove")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Winfinite-recursion")
cadna_enable_cxx_compiler_flag2(COMPILER_WARNINGS "Wno-c++98-compat" "Wno_c__98_compat_AVAILABLE")

cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "march=native")
cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS2 "ffast-math")

cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility=hidden")
cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility-inlines-hidden")

if((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL "Release"))
  set(OPTIMISATION_FLAGS "-O3 -DNDEBUG ${OPTIMISATION_FLAGS}")
endif((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL "Release"))

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions("-g")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

option(enable-libcxx "use LLVM C++ Standard library" OFF)
if(enable-libcxx)
  cadna_enable_cxx_compiler_flag(COMPILER_CXXFLAGS "stdlib=libc++")
endif(enable-libcxx)

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.4)
  message(FATAL_ERROR "CADNA C++11 support is only available for clang version >= 3.4")
endif(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.4)
set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -std=c++11")
set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -frounding-math")