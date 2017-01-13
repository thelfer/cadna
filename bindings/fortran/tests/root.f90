program main
  use cadna
  type(double_st) :: a
  type(double_st) :: b
  type(double_st) :: c
  type(double_st) :: d
  a = 0.3
  b = 2.1
  c = 3.657
  d = b*b-4*a*c
  write(*,*) nb_significant_digit(d)
end program main
