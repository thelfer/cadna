/*!
 * \file   test8.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   28 sept. 2015
 */

#ifdef NDEBUG
#undef NDEBUG
#endif /* NDEBUG */

#include<iostream>
#include<cstdlib>
#include<cassert>
#include "cadna.h"

int main(void)
{
  const double_st a{1.e15};
  const double_st b{1.e-15};
  const auto c = a+b;
  std::cout << c << std::endl;
  return 0;
}
