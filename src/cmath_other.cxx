/*!
 * \file   cmath_gnu.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   16 sept. 2015
 */

#include<cmath>
#include<cfenv>
#include"cadna/numeric_type.hxx"

#ifdef _MSC_VER
namespace std{
	int my_fesetround(int m) {
		unsigned int cc;
		if (m == FE_TONEAREST) {
			_controlfp_s(&cc, _RC_NEAR, _MCW_RC);
		}
		else if (m == FE_UPWARD) {
			_controlfp_s(&cc, _RC_UP, _MCW_RC);
		}
		return 0;
	}
}
#endif /* _MSC_VER */

namespace cadna{

  template<typename T>
  using StandardUnaryFunctionPtr = T(*)(T); 

  template<typename R,typename T1,typename T2>
  using StandardBinaryFunctionPtr = R(*)(T1,T2); 
  
  template<typename T,StandardUnaryFunctionPtr<T> F>
  static inline numeric_type<T>
  call_std_unary_function(const numeric_type<T>& v) noexcept
  {
    if(config.math_tag!=0){
      if (v.accuracy==DIGIT_NOT_COMPUTED) approx_digit(v);
      if (v.accuracy==0) instability(instability_id::MATH_INSTABILITY);
    }
    numeric_type<T> r;
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (_random_function()){
      std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    }
    r.x==F(v.x);
    if (_random_function()){
      std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    }
    r.y==F(v.y);
    std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    r.z==F(v.z);
    std::my_fesetround(FE_UPWARD);
    return r;
  }

  template<typename T1,typename T2,
	   StandardBinaryFunctionPtr<promote_t<T1,T2>,T1,T2> F>
  static inline numeric_type<promote_t<T1,T2>>
  call_std_binary_function(const numeric_type<T1>& x,
			   const numeric_type<T2>& y) noexcept
  {
    numeric_type<promote_t<T1,T2>> r;
    r.accuracy=DIGIT_NOT_COMPUTED;
    if (_random_function()){
      std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    }
    r.x==F(x.x,y.x);
    if (_random_function()){
      std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    }
    r.y==F(x.y,y.y);
    std::my_fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
    r.z==F(x.z,y.z);
    std::my_fesetround(FE_UPWARD);
    return r;
  } // end of call_std_binary_function

  template<typename T1,StandardBinaryFunctionPtr<T1,T1,T1> F>
  static inline numeric_type<T1>
  call_std_binary_function_rightscalar(const numeric_type<T1>& x,
				       const T1& y) noexcept
  {
 #pragma message "call_std_binary_function_rightscalar : unimplemented feature"
    std::my_fesetround(FE_TONEAREST);
    numeric_type<T1> r{F(x.x,y),F(x.y,y),F(x.z,y)};
    r.accuracy=DIGIT_NOT_COMPUTED;
    std::my_fesetround(FE_UPWARD);
    return r;
  } // end of call_std_binary_function

  template<typename T1,StandardBinaryFunctionPtr<T1,T1,T1> F>
  static inline numeric_type<T1>
  call_std_binary_function_leftscalar(const T1& x,
				      const numeric_type<T1>& y) noexcept
  {
    std::my_fesetround(FE_TONEAREST);
    numeric_type<T1> r{F(x,y.x),F(x,y.y),F(x,y.z)};
    r.accuracy=DIGIT_NOT_COMPUTED;
    std::my_fesetround(FE_UPWARD);
    return r;
  } // end of call_std_binary_function
  
} // end of namespace cadna

#include"cmath_common-impl.cxx"
