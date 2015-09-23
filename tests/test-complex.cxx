/*!
 * \file   test-complex.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   17 sept. 2015
 */

#include<iostream>
#include<complex>
#include<cstdlib>
#include"cadna/numeric_type.hxx"

int main(void){
  using complex = std::complex<cadna::numeric_type<double>>;
  const complex a{1.,2.};
  const complex b{2.,4.};
  const auto c = a*b;
  std::cout << c << std::endl;
  return EXIT_SUCCESS;
} // end of main
