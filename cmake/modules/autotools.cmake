# some variables for compatibility with autotools
set(abs_top_srcdir   "${PROJECT_SOURCE_DIR}")
set(abs_top_builddir "${PROJECT_BINARY_DIR}")
set(top_srcdir       "${PROJECT_SOURCE_DIR}")
set(top_builddir     "${PROJECT_BINARY_DIR}")
set(prefix           "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix      "${CMAKE_INSTALL_PREFIX}/bin")
set(includedir       "${CMAKE_INSTALL_PREFIX}/include")
if(WIN32)
set(libdir           "${CMAKE_INSTALL_PREFIX}/bin")
else(WIN32)
set(libdir         "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}")
endif(WIN32)
set(cxx              "${CMAKE_CXX_COMPILER_NAME}")
