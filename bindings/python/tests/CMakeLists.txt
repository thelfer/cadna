macro(test_pymfront test)
  add_test(NAME pymfront${test}_py
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${test}.py)
  if(CMAKE_CONFIGURATION_TYPES)
    set_tests_properties(pymfront${test}_py
      PROPERTIES ENVIRONMENT "PYTHONPATH=$<TARGET_FILE_DIR:py_cadna>;")
  else(CMAKE_CONFIGURATION_TYPES)
    set_tests_properties(pymfront${test}_py
      PROPERTIES ENVIRONMENT "PYTHONPATH=${PROJECT_BINARY_DIR}/bindings/python/src")
  endif(CMAKE_CONFIGURATION_TYPES)
endmacro(test_pymfront)

test_pymfront(rump)
test_pymfront(root)
