/*!
 * \file   test-typetraits.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   01 oct. 2015
 */

#ifdef NDEBUG
#undef NDEBUG
#endif /* NDEBUG */

#include<cassert>
#include<cstdlib>
#include"cadna/type_traits.hxx"

int main(void)
{
  static_assert(std::is_floating_point<cadna::numeric_type<float>>::value,
		"cadna::numeric_type<float> is not a floating point type");
  static_assert(std::is_floating_point<cadna::numeric_type<double>>::value,
		"cadna::numeric_type<double> is not a floating point type");
  static_assert(std::is_floating_point<cadna::numeric_type<long double>>::value,
		"cadna::numeric_type<long double> is not a floating point type");
  static_assert(std::is_arithmetic<cadna::numeric_type<float>>::value,
		"cadna::numeric_type<float> is not an arithmetic type");
  static_assert(std::is_arithmetic<cadna::numeric_type<double>>::value,
		"cadna::numeric_type<double> is not an arithmetic type");
  static_assert(std::is_arithmetic<cadna::numeric_type<long double>>::value,
		"cadna::numeric_type<long double> is not an arithmetic type");
  return EXIT_SUCCESS;
}
