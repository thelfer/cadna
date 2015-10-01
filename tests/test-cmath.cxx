/*!
 * \file   test-cmath.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   28 sept. 2015
 */

#ifdef NDEBUG
#undef NDEBUG
#endif /* NDEBUG */

#include<cmath>
#include<limits>
#include<cassert>
#include<cstdlib>

#include"cadna/numeric_type.hxx"

//! a simple alias
template<typename T>
using StandardUnaryFunctionPtr = T(*)(T);
//! a simple alias
template<typename T>
using CadnaUnaryFunctionPtr =
  cadna::numeric_type<T> (*)(const cadna::numeric_type<T>&); 
//! a simple alias
template<typename T>
using StandardBinaryFunctionPtr = T(*)(T,T);
//! a simple alias
template<typename T>
using CadnaBinaryFunctionPtr =
  cadna::numeric_type<T> (*)(const cadna::numeric_type<T>&,
			     const cadna::numeric_type<T>&); 

template<typename T,
	 StandardUnaryFunctionPtr<T> F,
	 CadnaUnaryFunctionPtr<T> G>
static void test(const T v){
  const cadna::numeric_type<T> cv{v};
  const auto r  = F(v);
  const auto cr = G(cv);
  assert(std::abs(cr.x-r)<10*std::numeric_limits<T>::epsilon());
  assert(std::abs(cr.y-r)<10*std::numeric_limits<T>::epsilon());
  assert(std::abs(cr.z-r)<10*std::numeric_limits<T>::epsilon());
} // end of test

template<typename T,
	 StandardBinaryFunctionPtr<T> F,
	 CadnaBinaryFunctionPtr<T> G>
static void test(const T v1,const T v2){
  const cadna::numeric_type<T> cv1{v1};
  const cadna::numeric_type<T> cv2{v2};
  const auto r  = F(v1,v2);
  const auto cr = G(cv1,cv2);
  assert(std::abs(cr.x-r)<10*std::numeric_limits<T>::epsilon());
  assert(std::abs(cr.y-r)<10*std::numeric_limits<T>::epsilon());
  assert(std::abs(cr.z-r)<10*std::numeric_limits<T>::epsilon());
} // end of test

#define CADNA_CMATH_UNARYFUNCTION_TEST(F,V)	       \
  test<float,std::F,std::F>(static_cast<float>(V));    \
  test<double,std::F,std::F>(static_cast<double>(V));
#define CADNA_CMATH_BINARYFUNCTION_TEST(F,V1,V2)       \
  test<float,std::F,std::F>(static_cast<float>(V1),    \
                            static_cast<float>(V2));   \
  test<double,std::F,std::F>(static_cast<double>(V1),  \
			     static_cast<double>(V2));

int main(void){
  CADNA_CMATH_UNARYFUNCTION_TEST(cos,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(sin,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(tan,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(acos,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(asin,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(atan,0.5);
  CADNA_CMATH_BINARYFUNCTION_TEST(atan2,0.5,0.5);
  // hyperbolic functions
  CADNA_CMATH_UNARYFUNCTION_TEST(cosh,1.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(sinh,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(tanh,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(asinh,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(atanh,0.5);
  // exponential and logarithmic functions
  CADNA_CMATH_UNARYFUNCTION_TEST(exp,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(exp2,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(expm1,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(log,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(log2,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(log10,0.5);
  // power functions
  CADNA_CMATH_UNARYFUNCTION_TEST(sqrt,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(cbrt,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(erf,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(erfc,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(tgamma,0.5);
  CADNA_CMATH_UNARYFUNCTION_TEST(lgamma,0.5);
  CADNA_CMATH_BINARYFUNCTION_TEST(pow,0.5,0.5);
  CADNA_CMATH_BINARYFUNCTION_TEST(hypot,0.5,0.5);
  return EXIT_SUCCESS;
}
