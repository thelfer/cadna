include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories("${PROJECT_BINARY_DIR}/src")

macro(cadna_test test_arg)
  add_executable(${test_arg} EXCLUDE_FROM_ALL ${test_arg}.cxx)
  add_test(NAME ${test_arg} COMMAND ${test_arg})
  add_dependencies(check ${test_arg})
  if((CMAKE_HOST_WIN32) AND (NOT MSYS))
    set_property(TEST ${test_arg}
      PROPERTY ENVIRONMENT "PATH=$<TARGET_FILE_DIR:cadna_cxx>\;$ENV{PATH}")
  endif((CMAKE_HOST_WIN32) AND (NOT MSYS))
  target_link_libraries(${test_arg} cadna_cxx)
endmacro(cadna_test)

cadna_test(test1)
cadna_test(test2)
cadna_test(test3)
cadna_test(test4)
cadna_test(test5)
cadna_test(test6)
cadna_test(test7)
cadna_test(test8)
cadna_test(test-cmath)
cadna_test(test-typetraits)
cadna_test(test-numeric-type)

# libc++ is really touchy about complex
if(NOT (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  cadna_test(test-complex)
endif(NOT (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))

cadna_test(instability)