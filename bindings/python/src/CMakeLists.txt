include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")
include_directories(SYSTEM "${PYTHON_INCLUDE_DIRS}")

link_directories("${PROJECT_BINARY_DIR}/src")
link_directories("${Boost_LIBRARY_DIRS}")
link_directories("${PYTHON_LIBRARY_PATH}")

macro(python_lib_module name)
    if(${ARGC} LESS 1)
    message(FATAL_ERROR "python_lib_module : no source specified")
  endif(${ARGC} LESS 1)
  add_library(py_${name} MODULE ${ARGN})
  if(WIN32)
    set_target_properties(py_${name} PROPERTIES
      COMPILE_FLAGS "-DHAVE_ROUND")
    set_target_properties(py_${name} PROPERTIES SUFFIX ".pyd")
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set_target_properties(py_${name} PROPERTIES SUFFIX ".so")
  endif(WIN32)
  set_target_properties(py_${name} PROPERTIES PREFIX "")
  set_target_properties(py_${name} PROPERTIES OUTPUT_NAME ${name})
  target_link_libraries(py_${name}
    ${Boost_PYTHON_LIBRARY} ${PYTHON_LIBRARIES})
  install(TARGETS py_${name}
    DESTINATION lib${LIB_SUFFIX}/${PYTHON_LIBRARY}/site-packages
    COMPONENT python_bindings)
endmacro(python_lib_module)

macro(cadna_python_module name)
endmacro(cadna_python_module)

python_lib_module(cadna
  cadna.cxx
  )
target_link_libraries(py_cadna cadna_cxx)
