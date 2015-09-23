/*!
 * \file   to_string.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   15 sept. 2015
 */

#include<sstream>
#include"cadna/numeric_type.hxx"

namespace std{

  std::string to_string(const cadna::numeric_type<float>& v)
  {
    std::ostringstream o;
    o << v;
    return o.str();
  }

  std::string to_string(const cadna::numeric_type<double>& v){
    std::ostringstream o;
    o << v;
    return o.str();
  }

}
