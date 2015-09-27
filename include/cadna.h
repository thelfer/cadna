/*!
 * \file   cadna.h  
 * \brief This file provide some type aliases and inject some
 * functions in the anonymous namespace. This header is mainly
 * provided for backward compatibility with previous versions of
 * CADNA.
 * \author Helfer Thomas
 * \date   09/2015
 * \copyright Copyright 2015 J.-M. Chesneaux, P. Eberhart,
 * F. Jezequel, J.-L. Lamotte, T. Helfer
 * This file is part of CADNA.
 * CADNA is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * You should have received a copy of the GNU Lesser General Public License
 * along with CADNA.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LIB_CADNA_HXX_
#define _LIB_CADNA_HXX_

#include"cadna/numeric_type.hxx"

//! a simple alias
using double_st = cadna::numeric_type<double>;
//! a simple alias
using float_st  = cadna::numeric_type<float>;
/*!
 * \brief The function injects the `cadna::init` function in the
 * anonymous namespace.
 * \param[in] a1 : maximum number of instabilities treated. If the
 * number of instabilities gets larger than this maximum, new
 * instabilities are ignored. If a negative number is specified, there
 * is no limit to the number of instabilities treated (the default).
 * \param[in] a2 : 
 * \param[in] a3 : 
 * \param[in] a4 : 
 * \note The `cadna_init` shall be called at beginning of the main
 * function.
 */
inline void cadna_init(const int a1,
		       const unsigned int a2,
		       const unsigned int a3,
		       const unsigned int a4){
  cadna::init(a1,a2,a3,a4);
}
/*!
 * \brief The function injects the `cadna::init` function in the
 * anonymous namespace.
 * \param[in] a1 : maximum number of instabilities treated. If the
 * number of instabilities gets larger than this maximum, new
 * instabilities are ignored. If a negative number is specified, there
 * is no limit to the number of instabilities treated (the default).
 * \param[in] a2 : 
 * \note The `cadna_init` shall be called at beginning of the main
 * function.
 */
inline void cadna_init(const int a1,const unsigned int a2){
  cadna::init(a1,a2);
}
/*!
 * \brief The function injects the `cadna::init` function in the
 * anonymous namespace.
 * \param[in] a1 : maximum number of instabilities treated. If the
 * number of instabilities gets larger than this maximum, new
 * instabilities are ignored. If a negative number is specified, there
 * is no limit to the number of instabilities treated (the default).
 * \note The `cadna_init` shall be called at beginning of the main
 * function.
 */
inline void cadna_init(const int a){
  cadna::init(a);
}
/*!
 * \brief The `cadna_end` function was meant to be called at the end
 * of the main function. This is now useless.
 */
inline void cadna_end(){}
/*!
 * \brief The function injects the `cadna::enable` function in the
 * anonymous namespace.
 */
inline void enable(const unsigned int a) {
  cadna::enable(a);
}
/*!
 * \brief The function injects the `cadna::disable` function in the
 * anonymous namespace.
 */
inline void disable(const unsigned int a){
  cadna::disable(a);
}
/*!
 * \brief The function injects the `cadna::internal_strp` function in
 * the anonymous namespace.
 */
inline const char* strp(const double_st& v){
  return cadna::internal_strp(v);
} // end of strp
/*!
 * \brief The function injects the `cadna::internal_strp` function in
 * the anonymous namespace.
 */
inline const char* strp(const float_st& v){
  return cadna::internal_strp(v);
} // end of strp
/*!
 * \brief The function injects the `cadna::set_rnd_arr` function in
 * the anonymous namespace.
 */
inline void cadna_set_rnd_arr(void) noexcept{
  cadna::set_rnd_arr();
}
/*!
 * \brief The function injects the `cadna::set_rnd_plinf` function in
 * the anonymous namespace.
 */
inline void cadna_set_rnd_plinf(void) noexcept{
  cadna::set_rnd_plinf();
}
/*!
 * \brief The function injects the `cadna::set_rnd_moinf` function in
 * the anonymous namespace.
 */
inline void cadna_set_rnd_moinf(void) noexcept{
  cadna::set_rnd_moinf();
}
/*!
 * \brief The function injects the `cadna::set_rnd_zero` function in
 * the anonymous namespace.
 */
inline void cadna_set_rnd_zero(void) noexcept{
  cadna::set_rnd_zero();
}
  
#endif  /*  _LIB_CADNA_HXX_ */
