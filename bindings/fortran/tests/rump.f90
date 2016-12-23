type (double_st) function rump(x,y)
  use cadna
  implicit none
  type (double_st), intent(in) :: x,y
  rump=9*x*x*x*x-y*y*y*y+2*y*y;
end function rump

program main
  use cadna
  implicit none
  type(double_st) x,y,z
  type(double_st),external :: rump
  x = double_st(10864)
  y = double_st(18817)
  z = rump(x,y)
  if (.not.numericalnoise(z)) then
     write(*,*) 'z is not numerical noise'
     call exit(1)
  endif
  if (nb_significant_digit(z).ne.0) then
     write(*,*) 'z has at least significant digit'
     call exit(1)
  endif
end program main
