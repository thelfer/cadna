module cadna
  use iso_c_binding
  type, bind(c) :: double_st
     real(c_double) :: x
     real(c_double) :: y
     real(c_double) :: z
     integer(c_int),private :: accuracy
  end type double_st
  interface
     type(double_st) function cadna_fortran_double_st_new (v) bind ( c )
       use iso_c_binding
       import :: double_st
       real (kind=8), intent(in) :: v
     end function cadna_fortran_double_st_new
     type(double_st) function cadna_fortran_double_st_new2 (v) bind ( c )
       use iso_c_binding
       import :: double_st
       real (kind=4), intent(in) :: v
     end function cadna_fortran_double_st_new2
     type(double_st) function cadna_fortran_double_st_new3 (v) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (kind=4), intent(in) :: v
     end function cadna_fortran_double_st_new3
     type(double_st) function cadna_fortran_double_st_new4 (v) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (kind=8), intent(in) :: v
     end function cadna_fortran_double_st_new4
     subroutine cadna_fortran_double_st_assign (self,src) bind ( c )
       use iso_c_binding
       import :: double_st
       type(double_st), intent(out) :: self
       real (kind=8), intent(in) :: src
     end subroutine cadna_fortran_double_st_assign
     subroutine cadna_fortran_double_st_assign2 (self,src) bind ( c )
       use iso_c_binding
       import :: double_st
       type(double_st), intent(out) :: self
       real (kind=4), intent(in) :: src
     end subroutine cadna_fortran_double_st_assign2
     subroutine cadna_fortran_double_st_assign3 (self,src) bind ( c )
       use iso_c_binding
       import :: double_st
       type(double_st), intent(out) :: self
       integer (kind=4), intent(in) :: src
     end subroutine cadna_fortran_double_st_assign3
     subroutine cadna_fortran_double_st_assign4 (self,src) bind ( c )
       use iso_c_binding
       import :: double_st
       type(double_st), intent(out) :: self
       integer (kind=8), intent(in) :: src
     end subroutine cadna_fortran_double_st_assign4
     type(double_st) function cadna_fortran_double_st_add (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_double_st_add
     type(double_st) function cadna_fortran_double_st_add1 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_double_st_add1
     type(double_st) function cadna_fortran_double_st_add2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_add2
     type(double_st) function cadna_fortran_double_st_add3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_double_st_add3
     type(double_st) function cadna_fortran_double_st_add4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_add4
     type(double_st) function cadna_fortran_double_st_sub (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_double_st_sub
     type(double_st) function cadna_fortran_double_st_sub1 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_double_st_sub1
     type(double_st) function cadna_fortran_double_st_sub2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_sub2
     type(double_st) function cadna_fortran_double_st_sub3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_double_st_sub3
     type(double_st) function cadna_fortran_double_st_sub4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_sub4
     type(double_st) function cadna_fortran_double_st_mul (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_double_st_mul
     type(double_st) function cadna_fortran_double_st_mul1 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_double_st_mul1
     type(double_st) function cadna_fortran_double_st_mul2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_mul2
     type(double_st) function cadna_fortran_double_st_mul3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_double_st_mul3
     type(double_st) function cadna_fortran_double_st_mul4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_mul4
     type(double_st) function cadna_fortran_double_st_div (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1,v2
     end function cadna_fortran_double_st_div
     type(double_st) function cadna_fortran_double_st_div1 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       real (c_double), intent(in)  :: v2
     end function cadna_fortran_double_st_div1
     type(double_st) function cadna_fortran_double_st_div2 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       real (c_double), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_div2
     type(double_st) function cadna_fortran_double_st_div3 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v1
       integer (c_int), intent(in)  :: v2
     end function cadna_fortran_double_st_div3
     type(double_st) function cadna_fortran_double_st_div4 (v1,v2) bind ( c )
       use iso_c_binding
       import :: double_st
       integer (c_int), intent(in)  :: v1
       type (double_st), intent(in) :: v2
     end function cadna_fortran_double_st_div4
     integer(c_int) function cadna_fortran_double_st_numerical_noise (v) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v
     end function cadna_fortran_double_st_numerical_noise
     integer(c_int) function cadna_fortran_double_st_computedzero (v) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v
     end function cadna_fortran_double_st_computedzero
     integer(c_int) function nb_significant_digit (v) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v
     end function nb_significant_digit
     integer(c_int) function approx_digit (v) bind ( c )
       use iso_c_binding
       import :: double_st
       type (double_st), intent(in) :: v
     end function approx_digit
  end interface
  interface double_st
     procedure cadna_fortran_double_st_new
     procedure cadna_fortran_double_st_new2
     procedure cadna_fortran_double_st_new3
     procedure cadna_fortran_double_st_new4
  end interface double_st
   interface assignment(=)
     procedure cadna_fortran_double_st_assign
     procedure cadna_fortran_double_st_assign2
     procedure cadna_fortran_double_st_assign3
     procedure cadna_fortran_double_st_assign4
  end interface assignment(=)
  interface operator (+)
     procedure cadna_fortran_double_st_add
     procedure cadna_fortran_double_st_add1
     procedure cadna_fortran_double_st_add2
     procedure cadna_fortran_double_st_add3
     procedure cadna_fortran_double_st_add4
  end interface operator (+)
  interface operator (-)
     procedure cadna_fortran_double_st_sub
     procedure cadna_fortran_double_st_sub1
     procedure cadna_fortran_double_st_sub2
     procedure cadna_fortran_double_st_sub3
     procedure cadna_fortran_double_st_sub4
  end interface operator (-)
  interface operator (*)
     procedure cadna_fortran_double_st_mul
     procedure cadna_fortran_double_st_mul1
     procedure cadna_fortran_double_st_mul2
     procedure cadna_fortran_double_st_mul3
     procedure cadna_fortran_double_st_mul4
  end interface operator (*)
  interface operator (/)
     procedure cadna_fortran_double_st_div
     procedure cadna_fortran_double_st_div1
     procedure cadna_fortran_double_st_div2
     procedure cadna_fortran_double_st_div3
     procedure cadna_fortran_double_st_div4
  end interface operator (/)
contains  
  LOGICAL function numericalnoise (v)
    type (double_st), intent(in) :: v
    integer(c_int) :: b
    b = cadna_fortran_double_st_numerical_noise(v)
    numericalnoise = b.ne.0
  end function numericalnoise
  LOGICAL function computedzero (v)
    type (double_st), intent(in) :: v
    integer(c_int) :: b
    b = cadna_fortran_double_st_computedzero(v)
    computedzero = b.ne.0
  end function computedzero
end module cadna
