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
  x = double_st(10864._c_double)
  y = double_st(18817._c_double)
  z=rump(x,y)
  if(numericalnoise(z)) then
     write(*,*) 'numerical noise'
  endif
  write(*,*) nb_significant_digit(z)
end program main
