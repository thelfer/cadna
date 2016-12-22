module cadna
  use iso_c_binding
  type, bind(c) :: double_st
     real(c_double) :: x
     real(c_double) :: y
     real(c_double) :: z
     integer(c_int),private :: accuracy
  end type double_st
  interface
     type(double_st) function cadna_fortran_new_double_st (v) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in) :: v
     end function cadna_fortran_new_double_st
     type(double_st) function cadna_fortran_add (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_add
     type(double_st) function cadna_fortran_add2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_add2
     type(double_st) function cadna_fortran_add3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_add3
     type(double_st) function cadna_fortran_add4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_add4
     type(double_st) function cadna_fortran_add5 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_add5
     type(double_st) function cadna_fortran_sub (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_sub
     type(double_st) function cadna_fortran_mul (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_mul
     type(double_st) function cadna_fortran_mul2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_mul2
     type(double_st) function cadna_fortran_mul3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_mul3
     type(double_st) function cadna_fortran_mul4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_mul4
     type(double_st) function cadna_fortran_mul5 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_mul5
     type(double_st) function cadna_fortran_div (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_div
     integer(c_int) function numericalnoise (v) bind ( c, name="cadna_fortran_numerical_noise")
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v
     end function numericalnoise
  end interface
  interface double_st
    procedure cadna_fortran_new_double_st
  end interface
  interface operator (+)
     procedure cadna_fortran_add
     procedure cadna_fortran_add2
     procedure cadna_fortran_add3
     procedure cadna_fortran_add4
     procedure cadna_fortran_add5
  end interface operator (+)
  interface operator (-)
     procedure cadna_fortran_sub
  end interface operator (-)
  interface operator (*)
     procedure cadna_fortran_mul
     procedure cadna_fortran_mul2
     procedure cadna_fortran_mul3
     procedure cadna_fortran_mul4
     procedure cadna_fortran_mul5
  end interface operator (*)
  interface operator (/)
     procedure cadna_fortran_div
  end interface operator (/)
end module cadna
