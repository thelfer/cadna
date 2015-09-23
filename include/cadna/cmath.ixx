/*!
 * \file   cmath.ixx
 *
 * \brief This header declares the required macros to implement the
 * standard mathematical functions.
 * 
 * Those implementations relies on two template function
 * `call_std_unary_function` and `call_std_binary_function` which are
 * specialised in the cmath_***.cxx files on a per plateform
 * basis.
 *
 * \author THOMAS HELFER
 * \date   17 sept. 2015
 */

#ifndef _LIB_CADNA_CMATH_IXX_
#define _LIB_CADNA_CMATH_IXX_

#define CADNA_STDMATH_UNARYFUNCTION_IMPL_BASE( CADNA_TYPE , F )		        \
CADNA_BEGIN_NAMESPACE_STD				                        \
  cadna::CADNA_TYPE F(const cadna::CADNA_TYPE& v) noexcept{	                \
    using cadna::call_std_unary_function;                                       \
    return call_std_unary_function<cadna::CADNA_TYPE::value_type,std::F>(v);	\
  }						                                \
CADNA_END_NAMESPACE_STD

#define CADNA_STDMATH_DOUBLE_UNARYFUNCTION_IMPL( F )                             \
  CADNA_STDMATH_UNARYFUNCTION_IMPL_BASE( numeric_type<double> , F )              \
  cadna::numeric_type<double> F(const cadna::numeric_type<double>& v) noexcept { \
    return std::F(v);                                                            \
  }

#define CADNA_STDMATH_FLOAT_UNARYFUNCTION_IMPL( F )                                \
  CADNA_STDMATH_UNARYFUNCTION_IMPL_BASE( numeric_type<float> , F )                 \
  cadna::numeric_type<float> F##f(const cadna::numeric_type<float>& v) noexcept {  \
    return std::F(v);                                                              \
  }
#define CADNA_STDMATH_UNARYFUNCTION_IMPL( F )  \
  CADNA_STDMATH_DOUBLE_UNARYFUNCTION_IMPL( F ) \
  CADNA_STDMATH_FLOAT_UNARYFUNCTION_IMPL( F )

#define CADNA_STDMATH_BINARYFUNCTION_IMPL_CXX( F )                                            \
  CADNA_BEGIN_NAMESPACE_STD				                                      \
    cadna::numeric_type<double>                                                               \
    F(const cadna::numeric_type<double>& x,const cadna::numeric_type<double>& y) noexcept{    \
      return cadna::call_std_binary_function<double,double,std::F>(x,y);	              \
    }                                                                                         \
    cadna::numeric_type<double>                                                               \
    F(const cadna::numeric_type<double>& x,const cadna::numeric_type<float>& y) noexcept{     \
      return cadna::call_std_binary_function<double,float,std::F>(x,y);	                      \
    }                                                                                         \
    cadna::numeric_type<double>                                                               \
    F(const cadna::numeric_type<float>& x,const cadna::numeric_type<double>& y) noexcept{     \
      return cadna::call_std_binary_function<float,double,std::F>(x,y);                       \
    }                                                                                         \
    cadna::numeric_type<double>                                                               \
    F(const cadna::numeric_type<double>& x,const double y) noexcept{	                      \
      return cadna::call_std_binary_function_rightscalar<double,std::F>(x,y);	              \
    }                                                                                         \
    cadna::numeric_type<double>                                                               \
    F(const double x,const cadna::numeric_type<double>& y) noexcept{	                      \
      return cadna::call_std_binary_function_leftscalar<double,std::F>(x,y);	              \
    }                                                                                         \
    cadna::numeric_type<float>                                                                \
    F(const cadna::numeric_type<float>& x,const cadna::numeric_type<float>& y) noexcept{      \
      return cadna::call_std_binary_function<float,float,std::F>(x,y);                        \
    }                                                                                         \
    cadna::numeric_type<float>                                                                \
    F(const cadna::numeric_type<float>& x,const float y) noexcept{	                      \
      return cadna::call_std_binary_function_rightscalar<double,std::F>(x,y);	              \
    }                                                                                         \
    cadna::numeric_type<float>                                                                \
    F(const float x,const cadna::numeric_type<float>& y) noexcept{	                      \
      return cadna::call_std_binary_function_leftscalar<double,std::F>(x,y);	              \
    }                                                                                         \
  CADNA_END_NAMESPACE_STD                                                                     \
  cadna::numeric_type<double>                                                                 \
  F(const cadna::numeric_type<double>& x,const cadna::numeric_type<double>& y) noexcept{      \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  cadna::numeric_type<double>                                                                 \
  F(const cadna::numeric_type<double>& x,const cadna::numeric_type<float>& y) noexcept{	      \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  cadna::numeric_type<double>                                                                 \
  F(const cadna::numeric_type<float>& x,const cadna::numeric_type<double>& y) noexcept{	      \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  cadna::numeric_type<float>                                                                  \
  F##f(const cadna::numeric_type<float>& x,const cadna::numeric_type<float>& y) noexcept{     \
    return std::F(x,y);                                                                       \
  }

#define CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX( F )                                            \
  CADNA_BEGIN_NAMESPACE_STD				                                      \
    template<typename T1,typename T2>						              \
    typename std::enable_if<(cadna::is_cxx_fundamental_type<T1>::value&&                      \
			     cadna::is_cxx_fundamental_type<T2>::value),                      \
			    cadna::numeric_type<T1>>::type                                    \
    F(const cadna::numeric_type<T1>& x,const T2 y) noexcept{	                              \
    return std::F(x,static_cast<T1>(y));				                      \
    }                                                                                         \
    template<typename T1,typename T2>						              \
    typename std::enable_if<(cadna::is_cxx_fundamental_type<T1>::value&&                      \
			     cadna::is_cxx_fundamental_type<T2>::value),                      \
			    cadna::numeric_type<T2>>::type                                    \
    F(const T1 x,const cadna::numeric_type<T2>& y) noexcept{	                              \
      return std::F(static_cast<T2>(x),y);						      \
    }                                                                                         \
  CADNA_END_NAMESPACE_STD                                                                     \
  template<typename T2>						                              \
  typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,                          \
			  cadna::numeric_type<double>>::type                                  \
  F(const cadna::numeric_type<double>& x,const T2 y) noexcept{	                              \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  template<typename T2>						                              \
  typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,                          \
			  cadna::numeric_type<double>>::type                                  \
  F(const T2 x,const cadna::numeric_type<double>& y) noexcept{	                              \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  template<typename T2>						                              \
  typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,                          \
			  cadna::numeric_type<float>>::type                                   \
  F##f(const cadna::numeric_type<float>& x,const T2 y) noexcept{	                      \
    return std::F(x,y);                                                                       \
  }                                                                                           \
  template<typename T2>						                              \
  typename std::enable_if<cadna::is_cxx_fundamental_type<T2>::value,                          \
			  cadna::numeric_type<float>>::type                                   \
  F##f(const T2 x,const cadna::numeric_type<float>& y) noexcept{	                      \
    return std::F(x,y);                                                                       \
  }

CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX(pow)
CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX(atan2)
CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX(fmax)
CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX(fmin)
CADNA_STDMATH_BINARYFUNCTION_IMPL_IXX(hypot)

#endif /* _LIB_CADNA_CMATH_IXX_ */
