#include "stdio.h"
#include <math.h>
#include "cadna.h"
int main()
{
  double_st r,r1,x,y,z;
  int i, nloop, ierr;
  // printf("Enter the number of iterations: ");
  // scanf("%d",&nloop);
  nloop=10;
  ierr = 0;
  for(i=0;i<nloop;i++){
    x=6.83561e+5;
    y=6.83560e+5;
    z=1.00000000007;
    r = z - x;
    r1 = z - y;
    r = r + y;
    r1 = r1 + x;
    r1 = r1 - 2;
    r = r + r1;
    //      r = ((z-x)+y) + ((z-y)+x-2)
    printf("iter %d, r = %s\n",i,strp(r));
    if(r != 1.4e-10) ierr = ierr + 1;
  }
  printf("r = %s   ierr = %d \n", strp(r) ,ierr);
  return 0;
}

