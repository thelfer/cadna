/*!
 * \file   to_string.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   15 sept. 2015
 */

#ifndef _LIB_CADNA_TO_STRING_HXX_
#define _LIB_CADNA_TO_STRING_HXX_

#include<string>
#include"cadna/macros.hxx"

namespace std{

  CADNA_VISIBILITY_EXPORT std::string
  to_string(const cadna::numeric_type<float>&);

  CADNA_VISIBILITY_EXPORT std::string
  to_string(const cadna::numeric_type<double>&);
  
} // end of namespace std

#endif /* _LIB_CADNA_TO_STRING_HXX_ */
