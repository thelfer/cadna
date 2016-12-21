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

option(enable-python-bindings "enable  python bindings support" OFF)
if(enable-python-bindings)
  find_package(PythonLibs   REQUIRED)
  find_package(PythonInterp REQUIRED)
  set(HAVE_PYTHON ON)
  add_definitions("-DHAVE_PYTHON=1")
  add_definitions("-DCADNA_PYTHON_INCLUDES=\\\"\"-I${PYTHON_INCLUDE_DIRS}\"\\\"")
  get_filename_component(PYTHON_LIBRARY_PATH ${PYTHON_LIBRARIES} PATH)
  get_filename_component(PYTHON_LIBRARY_FULL ${PYTHON_LIBRARIES} NAME)
  string(REGEX REPLACE "lib(.+)\\.(.+)$" "\\1" PYTHON_LIBRARY ${PYTHON_LIBRARY_FULL})
  add_definitions("-DCADNA_PYTHON_LIBS=\\\"\"-L${PYTHON_LIBRARY_PATH} -l${PYTHON_LIBRARY}\"\\\"")
  message(STATUS "found python          ${PYTHON_VERSION}")
  message(STATUS "python include path   ${PYTHON_INCLUDE_DIRS}")
  message(STATUS "python libraries path ${PYTHON_LIBRARY_PATH}")
  message(STATUS "python library        ${PYTHON_LIBRARY}")
  if(NOT HAVE_PYTHON)
    message(FATAL_ERROR "python not found. python is mandatory for python bindings.")
  endif(NOT HAVE_PYTHON)
  find_package(Boost 1.36.0 COMPONENTS python)
  if(Boost_FOUND)
    get_filename_component(Boost_PYTHON_LIBRARY ${Boost_PYTHON_LIBRARY} NAME)
    message(STATUS "Boost library python found (${Boost_PYTHON_LIBRARY}).")
  else(Boost_FOUND)
    message(FATAL_ERROR "Boost libraries not found.\n"
      "Required packages are :" ${BOOST_MANDATORY_COMPONENTS})
  endif(Boost_FOUND)
  list(APPEND CPACK_COMPONENTS_ALL python_bindings)
  set(CPACK_COMPONENT_PYTHON_BINDINGS_DEPENDS core)
endif(enable-python-bindings)


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
add_subdirectory(bindings)
add_subdirectory(tests)

set(CPACK_PACKAGE_VERSION   "${CMAKE_PROJECT_NAME}-${CADNA_VERSION}")
if(${CMAKE_SYSTEM_PROCESSOR})
  set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_PROCESSOR}") 
else(${CMAKE_SYSTEM_PROCESSOR})
  set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_VERSION}") 
endif(${CMAKE_SYSTEM_PROCESSOR})
set(CPACK_PACKAGE_INSTALL_DIRECTORY   "${CPACK_PACKAGE_VERSION}")
set(CPACK_PACKAGE_NAME                "${PACKAGE_NAME}")
set(CPACK_PACKAGE_CONTACT             "${PACKAGE_BUGREPORT}")
set(CPACK_PACKAGE_VERSION_PATCH       "${CADNA_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION_MAJOR       "${CADNA_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR       "${CADNA_VERSION_MINOR}")
set(CPACK_PACKAGE_VENDOR              "CEA_EDF")
set(CPACK_SOURCE_IGNORE_FILES         "build;/\\\\.svn/;.*~")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CADNA is a numerical library.")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENCE-GNU-LGPL")

# rpm packaging
set(CPACK_RPM_COMPONENT_INSTALL ON)
set(CPACK_RPM_PACKAGE_LICENSE "GPL/CECILL-A")

# debian packaging
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER   "Helfer Thomas ${PACKAGE_BUGREPORT}")
set(CPACK_DEBIAN_PACKAGE_SECTION      "Science")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE     "${CADNA_WEBSITE}")

#NSIS
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_MUI_ICON       "${CMAKE_SOURCE_DIR}/docs/cadna.ico")
set(CPACK_NSIS_MUI_UNIICON    "${CMAKE_SOURCE_DIR}/docs/cadna.ico")
set(CPACK_NSIS_URL_INFO_ABOUT "${CADNA_WEBSITE}")
set(CPACK_NSIS_HELP_LINK "${CADNA_WEBSITE}")
set(CPACK_NSIS_CONTACT "${PACKAGE_BUGREPORT}")
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_NSIS_INSTALL_ROOT "C:")
set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
      SetRegView  64
      WriteRegStr HKCR 'CADNAHOME-${CADNA_VERSION}' '' '$INSTDIR'")
set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
      SetRegView  64
      DeleteRegKey HKCR 'CADNAHOME-${CADNA_VERSION}'")

# if(UNIX)
#   add_custom_target(dist-bzip2
#     COMMAND svn export svn://localhost/PLEIADES/SVN/CADNA/trunk 
#     ${CMAKE_BINARY_DIR}/${PACKAGE_NAME}-${VERSION}
#     COMMAND tar -cvjf ${CMAKE_BINARY_DIR}/${PACKAGE_NAME}-${VERSION}.tar.bz2 
#     ${CMAKE_BINARY_DIR}/${PACKAGE_NAME}-${VERSION}
#     COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/${PACKAGE_NAME}-${VERSION}
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
# endif(UNIX)

# packaging
include(CPack)
