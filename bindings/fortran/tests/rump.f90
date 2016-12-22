function rump(x,y)
  use cadna
  implicit none
  type (double_st) :: rump
  type (double_st), intent(in) :: x,y
  rump=9*x*x*x*x-y*y*y*y+2*y*y;
end function rump

program main
  use cadna
  implicit none
  type(double_st) x
  type(double_st) y
  type(double_st) z
  type(double_st),external :: rump
  x = double_st(10864.)
  y = double_st(18817.)
  z=rump(x,y)
  if(numericalnoise(rump(x,y))==0) then
     write(*,*) 'numerical noise'
  endif
end program main
