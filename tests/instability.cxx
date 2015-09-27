/*!
 * \file   instability.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   23 sept. 2015
 */

#include<cstdlib>
#include<sstream>
#include<iostream>

#include"cadna/numeric_type.hxx"
#include"cadna/logstream.hxx"

int main(void){
  cadna::numeric_type<double> a{1};
  cadna::numeric_type<double> b{1};
  a.accuracy = 0;
  b.accuracy = 0;
  std::ostringstream o;
  cadna::add_logstream(o);
  const auto c = a*b;
  static_cast<void>(c);
  if(o.str().empty()){
    return EXIT_FAILURE;
  }
  std::cout << o.str() << std::endl;
  return EXIT_SUCCESS;
}
