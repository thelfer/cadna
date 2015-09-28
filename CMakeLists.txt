# Remove when CMake >= 2.8.4 is required
set(CMAKE_LEGACY_CYGWIN_WIN32 0) 
cmake_minimum_required(VERSION 2.4)
cmake_policy(SET CMP0005 OLD)

# cadna specific macros
include(cmake/modules/cadna.cmake)
# some variables for compatibility with autotools
include(cmake/modules/autotools.cmake)

#major and minor version
cadna_project(3 0 "0-dev")
set(PACKAGE_BUGREPORT "cadna-team@lip6.fr")

# check for the fenv package
include(CheckIncludeFiles)
check_include_files(fenv.h HAVE_FENV_H)

# compilers options
include(cmake/modules/compiler.cmake)
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
  include(cmake/modules/CodeCoverage.cmake)
  SETUP_TARGET_FOR_COVERAGE(coverage ctest coverage)
endif(CMAKE_BUILD_TYPE STREQUAL "Coverage")

# testing
set(CTEST_CONFIGURATION_TYPE "${JOB_BUILD_CONFIGURATION}")
# (must be placed *before* any add_subdirectory, cmake bug ?)
enable_testing()
if(CMAKE_CONFIGURATION_TYPES)
  add_custom_target(check COMMAND 
    ${CMAKE_CTEST_COMMAND} -T test -C $<CONFIGURATION>)
else(CMAKE_CONFIGURATION_TYPES)
  add_custom_target(check COMMAND 
    ${CMAKE_CTEST_COMMAND} -T test )
endif(CMAKE_CONFIGURATION_TYPES)

## environment under msys
if(CMAKE_HOST_WIN32 OR CYGWIN)
  if(MSYS)
     string(REGEX REPLACE "(.*):(.*)" "/\\1\\2"
             CADNA_BINARY_DIR "${PROJECT_BINARY_DIR}")
  else(MSYS)
     set(CADNA_BINARY_DIR "${PROJECT_BINARY_DIR}")
  endif(MSYS)	      
  if(CMAKE_CONFIGURATION_TYPES)
    foreach(conf ${CMAKE_CONFIGURATION_TYPES})
      set(CADNA_CONF_DIR "/${conf}")
      configure_file(env-win32.sh.in env-${conf}.sh @ONLY)
    endforeach(conf ${CMAKE_CONFIGURATION_TYPES})
  else(CMAKE_CONFIGURATION_TYPES)
    set(CADNA_CONF_DIR "")
    configure_file(env-win32.sh.in env.sh @ONLY)
  endif(CMAKE_CONFIGURATION_TYPES)
endif(CMAKE_HOST_WIN32 OR CYGWIN)

option(enable-openmp "enable openmp support" OFF)

if(enable-openmp)
  find_package(OpenMP)
  if(NOT OPENMP_FOUND)
    message(FATAL_ERROR "openmp not found")
  endif(NOT OPENMP_FOUND)
  message(STATUS "openmp found")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
  set(CADNA_COMPILER_CXXFLAGS "${CADNA_COMPILER_CXXFLAGS} ${OpenMP_CXX_FLAGS}")
  set(CADNA_COMPILER_LDFLAGS  "${CADNA_COMPILER_LDFLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_definitions("-DCADNA_COMPILER_WARNINGS=\"\\\"${COMPILER_WARNINGS}\"\\\"")
add_definitions("-DCADNA_COMPILER_CXXFLAGS=\"\\\"${CADNA_COMPILER_CXXFLAGS}\"\\\"")
if(CADNA_COMPILER_LDFLAGS)
  add_definitions("-DCADNA_COMPILER_LDFLAGS=\"\\\"${CADNA_COMPILER_LDFLAGS}\"\\\"")
endif(CADNA_COMPILER_LDFLAGS)

add_subdirectory(include) 
add_subdirectory(src)
add_subdirectory(cadna-config)
add_subdirectory(tests)
