/*!
 * \file   numeric_limits.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#ifndef _LIB_CADNA_NUMERIC_LIMITS_HXX_
#define _LIB_CADNA_NUMERIC_LIMITS_HXX_

#include<limits>
#include"cadna/numeric_type.hxx"

#define CADNA_NUMERIC_LIMITS_METHOD(X)	                   \
  static constexpr cadna::numeric_type<T> X() noexcept {   \
    return cadna::numeric_type<T>{numeric_limits<T>::X()}; \
  }
#define CADNA_NUMERIC_LIMITS_MEMBER(TYPE,X)		   \
    static constexpr TYPE X = numeric_limits<T>::X;

namespace std{

  template<typename T>
  struct numeric_limits<cadna::numeric_type<T>>
  {
    static constexpr bool is_specialized = true;
    CADNA_NUMERIC_LIMITS_METHOD(min)
    CADNA_NUMERIC_LIMITS_METHOD(max)
    CADNA_NUMERIC_LIMITS_METHOD(lowest)
    CADNA_NUMERIC_LIMITS_METHOD(epsilon)
    CADNA_NUMERIC_LIMITS_METHOD(round_error)
    CADNA_NUMERIC_LIMITS_METHOD(infinity)
    CADNA_NUMERIC_LIMITS_METHOD(quiet_NaN)
    CADNA_NUMERIC_LIMITS_METHOD(signaling_NaN)
    CADNA_NUMERIC_LIMITS_METHOD(denorm_min)
    CADNA_NUMERIC_LIMITS_MEMBER(int,digits)
    CADNA_NUMERIC_LIMITS_MEMBER(int,digits10)
    CADNA_NUMERIC_LIMITS_MEMBER(int,max_digits10)
    CADNA_NUMERIC_LIMITS_MEMBER(int,radix)
    CADNA_NUMERIC_LIMITS_MEMBER(int,min_exponent)
    CADNA_NUMERIC_LIMITS_MEMBER(int,min_exponent10)
    CADNA_NUMERIC_LIMITS_MEMBER(int,max_exponent)
    CADNA_NUMERIC_LIMITS_MEMBER(int,max_exponent10)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_signed)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_integer)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_exact)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,has_infinity)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,has_quiet_NaN)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,has_signaling_NaN)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,has_denorm_loss)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_iec559)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_bounded)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,is_modulo)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,traps)
    CADNA_NUMERIC_LIMITS_MEMBER(bool,tinyness_before)
    CADNA_NUMERIC_LIMITS_MEMBER(float_denorm_style,has_denorm)
    CADNA_NUMERIC_LIMITS_MEMBER(float_round_style,round_style)
  }; // end of struct numeric_limits<numeric_type<T>>
  
} // end of namespace std;

#endif /* _LIB_CADNA_NUMERIC_LIMITS_HXX_ */
