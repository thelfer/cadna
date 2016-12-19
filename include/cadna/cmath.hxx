/*!
 * \file   cmath.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   16 sept. 2015
 */

#ifndef _LIB_CADNA_CMATH_HXX_
#define _LIB_CADNA_CMATH_HXX_

#include<cmath>
#include"cadna/macros.hxx"
#include"cadna/numeric_type.hxx"

#define CADNA_STDMATH_DOUBLE_UNARYFUNCTION_DECL( F )                            \
  CADNA_BEGIN_NAMESPACE_STD				                        \
    CADNA_VISIBILITY_EXPORT                                                     \
    cadna::numeric_type<double> F(const cadna::numeric_type<double>&) noexcept;	\
  CADNA_END_NAMESPACE_STD		                                        \
  CADNA_VISIBILITY_EXPORT                                                       \
  cadna::numeric_type<double> F(const cadna::numeric_type<double>&) noexcept;

#define CADNA_STDMATH_FLOAT_UNARYFUNCTION_DECL( F )                             \
  CADNA_BEGIN_NAMESPACE_STD				                        \
    CADNA_VISIBILITY_EXPORT                                                     \
    cadna::numeric_type<float> F(const cadna::numeric_type<float>&) noexcept;	\
  CADNA_END_NAMESPACE_STD		                                        \
  CADNA_VISIBILITY_EXPORT                                                       \
  cadna::numeric_type<float> F##f(const cadna::numeric_type<float>&) noexcept;

#define CADNA_STDMATH_UNARYFUNCTION_DECL( F )  \
  CADNA_STDMATH_DOUBLE_UNARYFUNCTION_DECL( F ) \
  CADNA_STDMATH_FLOAT_UNARYFUNCTION_DECL( F )

#define CADNA_STDMATH_BINARYFUNCTION_DECL( F )                                          \
  CADNA_BEGIN_NAMESPACE_STD				                                \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<double> F(const cadna::numeric_type<double>&,                   \
                                  const cadna::numeric_type<double>&) noexcept;         \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<double> F(const cadna::numeric_type<double>&,                   \
                                  const double) noexcept;                               \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<double> F(const double,                                         \
                                  const cadna::numeric_type<double>&) noexcept;         \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<double> F(const cadna::numeric_type<double>&,                   \
				  const cadna::numeric_type<float>& ) noexcept;         \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<double> F(const cadna::numeric_type<float>& ,                   \
				  const cadna::numeric_type<double>&) noexcept;         \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<float>  F(const cadna::numeric_type<float>& ,                   \
				  const cadna::numeric_type<float>& ) noexcept;         \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<float> F(const cadna::numeric_type<float>&,                     \
                                 const float) noexcept;                                 \
    CADNA_VISIBILITY_EXPORT                                                             \
    cadna::numeric_type<float> F(const float,                                           \
                                 const cadna::numeric_type<float>&) noexcept;           \
    template<typename T1,typename T2>						        \
    CADNA_INLINE typename std::enable_if<(cadna::is_cxx_fundamental_type<T1>::value&&   \
				          cadna::is_cxx_fundamental_type<T2>::value),   \
				         cadna::numeric_type<T1>>::type                 \
    F(const cadna::numeric_type<T1>&,const T2) noexcept;                                \
    template<typename T1,typename T2>						        \
    CADNA_INLINE typename std::enable_if<(cadna::is_cxx_fundamental_type<T1>::value&&   \
				          cadna::is_cxx_fundamental_type<T2>::value),   \
				         cadna::numeric_type<T2>>::type                 \
    F(const T1,const cadna::numeric_type<T2>&) noexcept;                                \
  CADNA_END_NAMESPACE_STD		                                                \
  template<typename T2>						                        \
  CADNA_INLINE typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,       \
				       cadna::numeric_type<double>>::type               \
  F(const cadna::numeric_type<double>&,const T2) noexcept;	                        \
  template<typename T2>						                        \
  CADNA_INLINE typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,       \
				       cadna::numeric_type<double>>::type               \
  F(const T2,const cadna::numeric_type<double>&) noexcept;	                        \
  CADNA_VISIBILITY_EXPORT                                                               \
  cadna::numeric_type<double> F(const cadna::numeric_type<double>&,	                \
				const cadna::numeric_type<double>&) noexcept;           \
  CADNA_VISIBILITY_EXPORT                                                               \
  cadna::numeric_type<double> F(const cadna::numeric_type<double>&,	                \
				const cadna::numeric_type<float>&)  noexcept;           \
  CADNA_VISIBILITY_EXPORT                                                               \
  cadna::numeric_type<double> F(const cadna::numeric_type<float>& ,	                \
				const cadna::numeric_type<double>&) noexcept;           \
  CADNA_VISIBILITY_EXPORT                                                               \
  cadna::numeric_type<float>  F##f(const cadna::numeric_type<float>&,                   \
				   const cadna::numeric_type<float>&)  noexcept;        \
  template<typename T2>						                        \
  CADNA_INLINE typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,       \
				 cadna::numeric_type<float>>::type                      \
  F##f(const cadna::numeric_type<float>&,const T2) noexcept;		                \
  template<typename T2>						                        \
  CADNA_INLINE typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,       \
				 cadna::numeric_type<float>>::type                      \
  F##f(const T2,const cadna::numeric_type<float>&) noexcept;

// trigonometric functions
CADNA_STDMATH_UNARYFUNCTION_DECL(cos)
CADNA_STDMATH_UNARYFUNCTION_DECL(sin)
CADNA_STDMATH_UNARYFUNCTION_DECL(tan)
CADNA_STDMATH_UNARYFUNCTION_DECL(acos)
CADNA_STDMATH_UNARYFUNCTION_DECL(asin)
CADNA_STDMATH_UNARYFUNCTION_DECL(atan)
CADNA_STDMATH_BINARYFUNCTION_DECL(atan2)

// hyperbolic functions
CADNA_STDMATH_UNARYFUNCTION_DECL(cosh)
CADNA_STDMATH_UNARYFUNCTION_DECL(sinh)
CADNA_STDMATH_UNARYFUNCTION_DECL(tanh)
CADNA_STDMATH_UNARYFUNCTION_DECL(acosh)
CADNA_STDMATH_UNARYFUNCTION_DECL(asinh)
CADNA_STDMATH_UNARYFUNCTION_DECL(atanh)

// exponential and logarithmic functions
CADNA_STDMATH_UNARYFUNCTION_DECL(exp)
CADNA_STDMATH_UNARYFUNCTION_DECL(exp2)
CADNA_STDMATH_UNARYFUNCTION_DECL(expm1)

CADNA_STDMATH_UNARYFUNCTION_DECL(log)
CADNA_STDMATH_UNARYFUNCTION_DECL(log2)
CADNA_STDMATH_UNARYFUNCTION_DECL(log10)

// power functions
CADNA_STDMATH_UNARYFUNCTION_DECL(sqrt)
CADNA_STDMATH_UNARYFUNCTION_DECL(cbrt)
CADNA_STDMATH_BINARYFUNCTION_DECL(hypot)
CADNA_STDMATH_BINARYFUNCTION_DECL(pow)

// error and gamma function
CADNA_STDMATH_UNARYFUNCTION_DECL(erf)
CADNA_STDMATH_UNARYFUNCTION_DECL(erfc)
CADNA_STDMATH_UNARYFUNCTION_DECL(tgamma)
CADNA_STDMATH_UNARYFUNCTION_DECL(lgamma)

// intrinsic functions
CADNA_STDMATH_BINARYFUNCTION_DECL(fmax)
CADNA_STDMATH_BINARYFUNCTION_DECL(fmin)

CADNA_STDMATH_UNARYFUNCTION_DECL(floor)
CADNA_STDMATH_UNARYFUNCTION_DECL(ceil)
CADNA_STDMATH_UNARYFUNCTION_DECL(trunc)
CADNA_STDMATH_UNARYFUNCTION_DECL(nearbyint)
CADNA_STDMATH_UNARYFUNCTION_DECL(rint)

CADNA_BEGIN_NAMESPACE_STD
  CADNA_VISIBILITY_EXPORT cadna::numeric_type<double>
  abs(const cadna::numeric_type<double>&) noexcept;
  CADNA_VISIBILITY_EXPORT cadna::numeric_type<float>
  abs(const cadna::numeric_type<float>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isnan(const cadna::numeric_type<double>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isnan(const cadna::numeric_type<float>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isfinite(const cadna::numeric_type<double>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isfinite(const cadna::numeric_type<float>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isinf(const cadna::numeric_type<double>&) noexcept;
  CADNA_VISIBILITY_EXPORT bool
  isinf(const cadna::numeric_type<float>&) noexcept;
CADNA_END_NAMESPACE_STD
CADNA_VISIBILITY_EXPORT cadna::numeric_type<double>
fabs(const cadna::numeric_type<double>&) noexcept;
CADNA_VISIBILITY_EXPORT cadna::numeric_type<float>
fabsf(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isnan(const cadna::numeric_type<double>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isnan(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isnanf(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isfinite(const cadna::numeric_type<double>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isfinite(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isfinitef(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isinf(const cadna::numeric_type<double>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isinf(const cadna::numeric_type<float>&) noexcept;
CADNA_VISIBILITY_EXPORT bool
isinff(const cadna::numeric_type<float>&) noexcept;

#include"cadna/cmath.ixx"

#endif /* _LIB_CADNA_CMATH_HXX_ */
