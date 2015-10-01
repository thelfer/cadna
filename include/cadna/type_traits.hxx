/*!
 * \file   type_traits.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   01 oct. 2015
 */

#ifndef _LIB_CADNA_TYPE_TRAITS_HXX_
#define _LIB_CADNA_TYPE_TRAITS_HXX_

#include<type_traits>
#include"cadna/macros.hxx"
#include"cadna/numeric_type.hxx"

CADNA_BEGIN_NAMESPACE_STD

  /*!
   * \brief partial specialisation of the std::is_floating_point
   * metafunction
   */
  template<typename T>
  struct is_floating_point<cadna::numeric_type<T>>
    : std::conditional<cadna::is_cxx_floating_point_type<T>::value,
		       std::true_type,std::false_type>
  {}; // end of struct is_floating_point<cadna::numeric_type<T>>

CADNA_END_NAMESPACE_STD

#endif /* _LIB_CADNA__TYPE_TRAITS_HXX_ */
