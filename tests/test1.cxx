#include <cadna.h>
#include <stdio.h>

using namespace std;

int main(void)
{
  printf("------------------------------------------\n");
  printf("|  Polynomial function of two variables  |\n");
  printf("|  with CADNA                            |\n");
  printf("------------------------------------------\n");

  const double_st x = 77617.;
  const double_st y = 33096.;
  double_st res;
  res=333.75*y*y*y*y*y*y+x*x*(11*x*x*y*y-y*y*y*y*y*y-121*y*y*y*y-2.0)   
    +5.5*y*y*y*y*y*y*y*y+x/(2*y);
  printf("res=%s\n",strp(res));
  return 0;
}




