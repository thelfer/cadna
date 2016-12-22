struct double_st{
  double x;
  double y;
  double z;
  int  accuracy;
};

struct double_st cadna_add(const struct double_st* x,
			   const struct double_st* y){
  struct double_st z;
  z.x = x->x+2*y->x;
  z.y = 0;
  z.z = 0;
  return z;
}
