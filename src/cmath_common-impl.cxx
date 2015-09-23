/*!
 * \file   cmath_common-impl.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   17 sept. 2015
 */

#include<iostream>

#define CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL( F )    \
  CADNA_BEGIN_NAMESPACE_STD			      \
    cadna::numeric_type<double>			      \
    F(const cadna::numeric_type<double>& v) noexcept{ \
      return cadna::F##_impl(v);		      \
    }						      \
    cadna::numeric_type<float>			      \
    F(const cadna::numeric_type<float>& v) noexcept{  \
      return cadna::F##_impl(v);		      \
    }						      \
  CADNA_END_NAMESPACE_STD			      \
  cadna::numeric_type<double>			      \
  F(const cadna::numeric_type<double>& v) noexcept{   \
    return std::F(v);				      \
  }						      \
  cadna::numeric_type<float>			      \
  F##f(const cadna::numeric_type<float>& v) noexcept{ \
    return std::F(v);				      \
  }

CADNA_STDMATH_UNARYFUNCTION_IMPL(cos)
CADNA_STDMATH_UNARYFUNCTION_IMPL(sin)
CADNA_STDMATH_UNARYFUNCTION_IMPL(tan)
CADNA_STDMATH_UNARYFUNCTION_IMPL(acos)
CADNA_STDMATH_UNARYFUNCTION_IMPL(asin)
CADNA_STDMATH_UNARYFUNCTION_IMPL(atan)
CADNA_STDMATH_BINARYFUNCTION_IMPL_CXX(atan2)

CADNA_STDMATH_UNARYFUNCTION_IMPL(cosh)
CADNA_STDMATH_UNARYFUNCTION_IMPL(sinh)
CADNA_STDMATH_UNARYFUNCTION_IMPL(tanh)
CADNA_STDMATH_UNARYFUNCTION_IMPL(acosh)
CADNA_STDMATH_UNARYFUNCTION_IMPL(asinh)
CADNA_STDMATH_UNARYFUNCTION_IMPL(atanh)

CADNA_STDMATH_UNARYFUNCTION_IMPL(exp)
CADNA_STDMATH_UNARYFUNCTION_IMPL(exp2)
CADNA_STDMATH_UNARYFUNCTION_IMPL(expm1)

CADNA_STDMATH_UNARYFUNCTION_IMPL(log)
CADNA_STDMATH_UNARYFUNCTION_IMPL(log2)
CADNA_STDMATH_UNARYFUNCTION_IMPL(log10)

CADNA_STDMATH_UNARYFUNCTION_IMPL(sqrt)
CADNA_STDMATH_UNARYFUNCTION_IMPL(cbrt)
CADNA_STDMATH_BINARYFUNCTION_IMPL_CXX(hypot)
CADNA_STDMATH_UNARYFUNCTION_IMPL(erf)
CADNA_STDMATH_UNARYFUNCTION_IMPL(erfc)
CADNA_STDMATH_UNARYFUNCTION_IMPL(tgamma)
CADNA_STDMATH_UNARYFUNCTION_IMPL(lgamma)

CADNA_BEGIN_NAMESPACE_STD
  cadna::numeric_type<double>
  pow(const cadna::numeric_type<double>& x,const cadna::numeric_type<double>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (x.accuracy==0 || y.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function<double,double,std::pow>(x,y);
  }
  cadna::numeric_type<double>
  pow(const cadna::numeric_type<double>& x,const cadna::numeric_type<float>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (x.accuracy==0 || y.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function<double,float,std::pow>(x,y);
  }
  cadna::numeric_type<double>
  pow(const cadna::numeric_type<float>& x,const cadna::numeric_type<double>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (x.accuracy==0 || y.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function<float,double,std::pow>(x,y);
  }
  cadna::numeric_type<double>
  pow(const cadna::numeric_type<double>& x,const double y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (x.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function_rightscalar<double,std::pow>(x,y);
  }
  cadna::numeric_type<double>
  pow(const double x,const cadna::numeric_type<double>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (y.accuracy==0) cadna::instability(cadna::instability_id::POWER_INSTABILITY);
    }
    return cadna::call_std_binary_function_leftscalar<double,std::pow>(x,y);
  }
  cadna::numeric_type<float>
  pow(const cadna::numeric_type<float>& x,const cadna::numeric_type<float>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (x.accuracy==0 || y.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function<float,float,std::pow>(x,y);
  }
  cadna::numeric_type<float>
  pow(const cadna::numeric_type<float>& x,const float y) noexcept{
    if(cadna::config.power_tag!=0){
      if (x.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(x);
      if (x.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function_rightscalar<double,std::pow>(x,y);
  }
  cadna::numeric_type<float>
  pow(const float x,const cadna::numeric_type<float>& y) noexcept{
    if(cadna::config.power_tag!=0){
      if (y.accuracy==cadna::DIGIT_NOT_COMPUTED) approx_digit(y);
      if (y.accuracy==0){
	cadna::instability(cadna::instability_id::POWER_INSTABILITY);
      }
    }
    return cadna::call_std_binary_function_leftscalar<double,std::pow>(x,y);
  }
CADNA_END_NAMESPACE_STD
cadna::numeric_type<double>
pow(const cadna::numeric_type<double>& x,const cadna::numeric_type<double>& y) noexcept{
  return std::pow(x,y);
}
cadna::numeric_type<double>
pow(const cadna::numeric_type<double>& x,const cadna::numeric_type<float>& y) noexcept{
  return std::pow(x,y);
}
cadna::numeric_type<double>
pow(const cadna::numeric_type<float>& x,const cadna::numeric_type<double>& y) noexcept{
  return std::pow(x,y);
}
cadna::numeric_type<float>
powf(const cadna::numeric_type<float>& x,const cadna::numeric_type<float>& y) noexcept{
  return std::pow(x,y);
}

namespace cadna{
  template<typename T>
  static inline cadna::numeric_type<T>
  abs_impl(const cadna::numeric_type<T>& v) noexcept
  {
    numeric_type<T> r;
    if(v.x >= 0){
      r.x = v.x;
      if (config.intrinsic_tag){
	if ((v.y<0) || (v.z<0)){
	  instability(instability_id::INTRINSIC_INSTABILITY);
	}
      }
    }
    else{
      r.x = -v.x;
      if (config.intrinsic_tag){
	if ((v.y>0) || (v.z>0)){
	  instability(instability_id::INTRINSIC_INSTABILITY);
	}
      }
    }
    if(v.y >= 0)
      r.y = v.y;
    else
      r.y = -v.y;
    if(v.z >= 0)
      r.z = v.z;
    else
      r.z = -v.z;
    r.accuracy=DIGIT_NOT_COMPUTED;
    return r;
  }
  template<typename T>
  numeric_type<T> floor_impl(const numeric_type<T>& a) noexcept{
    numeric_type<T> r;
    r.x = std::floor(a.x);
    r.y = std::floor(a.y);
    r.z = std::floor(a.z);
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (config.intrinsic_tag)
      if (r.x != r.y || r.y!=r.z)
	instability(instability_id::INTRINSIC_INSTABILITY);
    return(r);
  }
  template<typename T>
  numeric_type<T> ceil_impl(const numeric_type<T>& a) noexcept{
    numeric_type<T> r;
    r.x = std::ceil(a.x);
    r.y = std::ceil(a.y);
    r.z = std::ceil(a.z);
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (config.intrinsic_tag)
      if (r.x != r.y || r.y!=r.z)
	instability(instability_id::INTRINSIC_INSTABILITY);
    return(r);
  }
  template<typename T>
  numeric_type<T> trunc_impl(const numeric_type<T>& a) noexcept{
    numeric_type<T> r;
    r.x = std::trunc(a.x);
    r.y = std::trunc(a.y);
    r.z = std::trunc(a.z);
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (config.intrinsic_tag)
      if (r.x != r.y || r.y!=r.z)
	instability(instability_id::INTRINSIC_INSTABILITY);
    return(r);
  }
  template<typename T>
  numeric_type<T> nearbyint_impl(const numeric_type<T>& a) noexcept{
    numeric_type<T> r;
    std::cerr << "CADNA WARNING: the nearbyint function is not CADNA compatible" << std::endl;
    r.x = std::nearbyint(a.x);
    r.y = std::nearbyint(a.y);
    r.z = std::nearbyint(a.z);
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (config.intrinsic_tag)
      if (r.x != r.y || r.y!=r.z)
	instability(instability_id::INTRINSIC_INSTABILITY);

    return(r);
  }
  template<typename T>
  numeric_type<T> rint_impl(const numeric_type<T>& a) noexcept{
    numeric_type<T> r;
    std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    r.x = std::rint(a.x);
    r.y = std::rint(a.y);
    r.z = std::rint(a.z);
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (config.intrinsic_tag)
      if (r.x != r.y || r.y!=r.z)
	instability(instability_id::INTRINSIC_INSTABILITY);
    return(r);
  }
} // end of namespace cadna

CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL(floor)
CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL(ceil)
CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL(trunc)
CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL(nearbyint)
CADNA_STDMATH_INTRINSIC_FUNCTION_IMPL(rint)

CADNA_BEGIN_NAMESPACE_STD  
  cadna::numeric_type<double>
  abs(const cadna::numeric_type<double>& v) noexcept{
    return cadna::abs_impl(v);
  }
  cadna::numeric_type<float>
  abs(const cadna::numeric_type<float>& v) noexcept{
    return cadna::abs_impl(v);
  }
  bool isnan(const cadna::numeric_type<double>& v) noexcept
  {
    const bool b=std::isnan(v.x);
    if(b != std::isnan(v.y) || b != std::isnan(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
  bool isnan(const cadna::numeric_type<float>& v) noexcept
  {
    const bool b=std::isnan(v.x);
    if(b != std::isnan(v.y) || b != std::isnan(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
  bool isfinite(const cadna::numeric_type<double>& v) noexcept
  {
    const bool b=std::isnan(v.x);
    if(b != std::isfinite(v.y) || b != std::isfinite(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
  bool isfinite(const cadna::numeric_type<float>& v) noexcept
  {
    const bool b=std::isfinite(v.x);
    if(b != std::isfinite(v.y) || b != std::isfinite(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
  bool isinf(const cadna::numeric_type<double>& v) noexcept
  {
    const bool b=std::isinf(v.x);
    if(b != std::isinf(v.y) || b != std::isinf(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
  bool isinf(const cadna::numeric_type<float>& v) noexcept
  {
    const bool b=std::isinf(v.x);
    if(b != std::isinf(v.y) || b != std::isinf(v.z) ){
      cadna::instability(cadna::instability_id::MATH_INSTABILITY);
    }
    return b;
  }
CADNA_END_NAMESPACE_STD
cadna::numeric_type<double>
fabs(const cadna::numeric_type<double>& v) noexcept{
  return std::abs(v);
}
cadna::numeric_type<float>
fabsf(const cadna::numeric_type<float>& v) noexcept{
  return std::abs(v);
}
bool isnan(const cadna::numeric_type<double>&v) noexcept{
  return std::isnan(v);
}
bool isnan(const cadna::numeric_type<float>&v) noexcept{
  return std::isnan(v);
}
bool isnanf(const cadna::numeric_type<float>&v) noexcept{
  return std::isnan(v);
}
bool isfinite(const cadna::numeric_type<double>& v) noexcept{
  return std::isfinite(v);
}
bool isfinite(const cadna::numeric_type<float>& v) noexcept{
  return std::isfinite(v);
}
bool isfinitef(const cadna::numeric_type<float>& v) noexcept{
  return std::isfinite(v);
}
bool isinf(const cadna::numeric_type<double>& v) noexcept{
  return std::isinf(v);
}
bool isinf(const cadna::numeric_type<float>& v) noexcept{
  return std::isinf(v);
}
bool isinff(const cadna::numeric_type<float>& v) noexcept{
  return std::isinf(v);
}
