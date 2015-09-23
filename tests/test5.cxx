#include <cadna.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
  int i, nmax=100;
  double_st y, x;

  cadna_init(-1,0,8966746,4);

  printf("-------------------------------------------------------------\n");
  printf("|  Computation of a root of a polynomial by Newton's method |\n");
  printf("|  with CADNA                                               |\n");
  printf("-------------------------------------------------------------\n");


  y = 0.5;
  
  for(i = 1;i<=nmax;i++){
    x = y;
      y = x-(1.47*pow(x,3)+1.19*pow(x,2)-1.83*x+0.45)/
      (4.41*pow(x,2)+2.38*x-1.83);
      if (fabs(x-y)<1.e-12) break;
  }
  printf("x(%3d) = %s\n",i-1,strp(x));
  printf("x(%3d) = %s\n",i,strp(y));
  return 0;
}




