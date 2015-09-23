# Remove when CMake >= 2.8.4 is required
set(CMAKE_LEGACY_CYGWIN_WIN32 0) 
cmake_minimum_required(VERSION 2.4)
# cmake_policy(SET CMP0005 OLD)

# if(CMAKE_MAJOR_VERSION VERSION_GREATER 2.8.12)
#   cmake_policy(SET CMP0026 OLD)
# endif(CMAKE_MAJOR_VERSION VERSION_GREATER 2.8.12)

# cadna specific macros
include(cmake/modules/cadna.cmake)
# some variables for compatibility with autotools
include(cmake/modules/autotools.cmake)

#major and minor version
cadna_project(3 0 "0-dev")
set(PACKAGE_BUGREPORT "cadna-team@lip6.fr")

# check for the fenv package
include(CheckIncludeFiles)
check_include_files(fenvh HAVE_FENV_H)
# if(NOT HAVE_FENV_H)
#   message(FATAL_ERROR "fenv.h header not found")
# endif(NOT HAVE_FENV_H)

set(CMAKE_CXX_FLAGS "-O3 -g -Wunused -frounding-math -std=c++11")
set(CMAKE_CXX_FLAGS "-fvisibility=hidden ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-fvisibility-inlines-hidden ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wall -W -Wextra -pedantic -Wshadow ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wpointer-arith -Wcast-qual -Wcast-align ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wwrite-strings -Wctor-dtor-privacy -Wnon-virtual-dtor ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Woverloaded-virtual -Wreturn-type ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wno-endif-labels -Wsign-compare -Wmissing-format-attribute ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wno-multichar -Wno-deprecated-declarations -Wpacked ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wredundant-decls ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wunknown-pragmas -Wundef -Wreorder ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wconversion ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Winit-self ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wlogical-op ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wmissing-declarations ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wmissing-include-dirs ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wnoexcept ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsign-conversion ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsign-promo ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wstrict-null-sentinel ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wtrampolines ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wvector-operation-performance ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wzero-as-null-pointer-constant ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wignored-qualifiers ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsequence-point ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wswitch ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsuggest-attribute=pure ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsuggest-attribute=const ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsuggest-attribute=noreturn ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wsuggest-attribute=format ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Winline ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wdouble-promotion -Wfloat-equal ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "-Wold-style-cast ${CMAKE_CXX_FLAGS}")

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

add_subdirectory(include) 
add_subdirectory(src)
add_subdirectory(tests)
