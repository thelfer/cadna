if(enable-python-bindings)
  add_subdirectory(python)
endif(enable-python-bindings)
if(enable-fortran-bindings)
  add_subdirectory(fortran)
endif(enable-fortran-bindings)

