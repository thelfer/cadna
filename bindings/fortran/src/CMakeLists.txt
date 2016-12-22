include_directories("${PROJECT_SOURCE_DIR}/include")

cadna_library(cadna_fortran
  numeric_type.f90
  numeric_type-wrapper.cxx)
target_link_libraries(cadna_fortran cadna_cxx)
