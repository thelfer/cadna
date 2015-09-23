/*!
 * \file   test.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   12 sept. 2015
 */

#include<iostream>
#include<cstdlib>
#include"cadna_numeric_type.hxx"
#include"cadna_numeric_limits.hxx"

int main(void){
  cadna::numeric_type<double> v{1};
  cadna::numeric_type<double> v2{3};
  if(v2>1.1*v2){
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  auto v3 = v+v2;
  std::cout << v3 << std::endl;
  ++v;
  std::cout << v << std::endl;
  v+=v2;
  std::cout << v << std::endl;
  v*=2;
  std::cout << v << std::endl;
  v/=4;
  std::cout << v << std::endl;
  std::cout << std::numeric_limits<cadna::numeric_type<double>>::epsilon() << std::endl;
  std::cout << std::numeric_limits<double>::epsilon() << std::endl;
  return EXIT_SUCCESS;
}
