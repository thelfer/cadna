macro(cadna_fortran_test test_arg)
  add_executable(fortran_${test_arg} EXCLUDE_FROM_ALL ${test_arg}.f90)
  add_test(NAME fortran_${test_arg} COMMAND fortran_${test_arg})
  add_dependencies(check fortran_${test_arg})
  if((CMAKE_HOST_WIN32) AND (NOT MSYS))
    set_property(TEST fortran_${test_arg}
      PROPERTY ENVIRONMENT "PATH=$<TARGET_FILE_DIR:cadna_fortran>\;$<TARGET_FILE_DIR:cadna_cxx>\;$ENV{PATH}")
  endif((CMAKE_HOST_WIN32) AND (NOT MSYS))
  target_link_libraries(fortran_${test_arg} cadna_fortran)
endmacro(cadna_fortran_test)

cadna_fortran_test(rump)
cadna_fortran_test(root)
