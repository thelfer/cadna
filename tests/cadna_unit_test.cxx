/*!
 * \file   cadna_unit_test.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#ifdef NDEBUG
#undef NDEBUG
#endif /* NDEBUG */

#include<stdexcept>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>

#include"cadna/global.hxx"
#include"cadna/numeric_type.hxx"

struct PlusEqual{
  template<typename T1,typename T2>
  static T1 exe(const T1& v1,const T2& v2){
    T1 r{v1};
    r += v2;
    return r;
  }
};

struct MinusEqual{
  template<typename T1,typename T2>
  static T1 exe(const T1& v1,const T2& v2){
    T1 r{v1};
    r -= v2;
    return r;
  }
};

struct MultEqual{
  template<typename T1,typename T2>
  static T1 exe(const T1& v1,const T2& v2){
    T1 r{v1};
    r *= v2;
    return r;
  }
};

struct DivEqual{
  template<typename T1,typename T2>
  static T1 exe(const T1& v1,const T2& v2){
    T1 r{v1};
    r /= v2;
    return r;
  }
};

struct Plus{
  template<typename T1,typename T2>
  static auto exe(const T1& v1,const T2& v2)
    -> decltype(v1+v2)
  {
    return v1+v2;
  }
};

struct Minus{
  template<typename T1,typename T2>
  static auto exe(const T1& v1,const T2& v2)
    -> decltype(v1-v2)
  {
    return v1-v2;
  }
};

struct Mult{
  template<typename T1,typename T2>
  static auto exe(const T1& v1,const T2& v2)
    -> decltype(v1*v2)
  {
    return v1*v2;
  }
};

struct Div{
  template<typename T1,typename T2>
  static auto exe(const T1& v1,const T2& v2)
    -> decltype(v1/v2)
  {
    return v1/v2;
  }
};


template<typename T1,typename T2>
static void assert_equal(const cadna::numeric_type<T1>& v1,const T2& v2){
  if(std::abs(v1.x-static_cast<T1>(v2))>std::numeric_limits<T1>::epsilon()){
    throw(std::runtime_error("assert_equal failed"));
  }
  if(std::abs(v1.y-static_cast<T1>(v2))>std::numeric_limits<T1>::epsilon()){
    throw(std::runtime_error("assert_equal failed"));
  }
  if(std::abs(v1.z-static_cast<T1>(v2))>std::numeric_limits<T1>::epsilon()){
    throw(std::runtime_error("assert_equal failed"));
  }
} // end of assert_equal

template<typename T1,typename T2,typename Op>
static void test(const T1& v1,const T2& v2)
{
  const cadna::numeric_type<T1> cv1{v1};
  const cadna::numeric_type<T2> cv2{v2};
  const auto r   = Op::exe(v1,v2);
  const auto cr1 = Op::exe(cv1,v2);
  const auto cr2 = Op::exe(cv1,cv2);
  assert_equal(cr1,r);
  assert_equal(cr2,r);
}

template<typename T1,typename T2,typename Op>
static void test2(const T1& v1,const T2& v2)
{
  const cadna::numeric_type<T1> cv1{v1};
  const cadna::numeric_type<T2> cv2{v2};
  const auto r   = Op::exe(v1,v2);
  const auto cr1 = Op::exe(cv1,v2);
  const auto cr2 = Op::exe(v1,cv2);
  const auto cr3 = Op::exe(cv1,cv2);
  assert_equal(cr1,r);
  assert_equal(cr2,r);
  assert_equal(cr3,r);
}


int main(void)
{
  test<double,double,PlusEqual>(double{1.2},double{0.5});
  test<double,float,PlusEqual>(double{1.2},float{0.5});
  test<float,double,PlusEqual>(float{1.2},double{0.5});
  test<float,float,PlusEqual>(float{1.2},float{0.5});
  test<double,double,MinusEqual>(double{1.2},double{0.5});
  test<double,float,MinusEqual>(double{1.2},float{0.5});
  test<float,double,MinusEqual>(float{1.2},double{0.5});
  test<float,float,MinusEqual>(float{1.2},float{0.5});
  test<double,double,MultEqual>(double{1.2},double{0.5});
  test<double,float,MultEqual>(double{1.2},float{0.5});
  test<float,double,MultEqual>(float{1.2},double{0.5});
  test<float,float,MultEqual>(float{1.2},float{0.5});
  test<double,double,DivEqual>(double{1.2},double{0.5});
  test<double,float,DivEqual>(double{1.2},float{0.5});
  test<float,double,DivEqual>(float{1.2},double{0.5});
  test<float,float,DivEqual>(float{1.2},float{0.5});

  test2<double,double,Plus>(double{1.2},double{0.5});
  test2<double,float,Plus>(double{1.2},float{0.5});
  test2<float,double,Plus>(float{1.2},double{0.5});
  test2<float,float,Plus>(float{1.2},float{0.5});
  test2<double,double,Minus>(double{1.2},double{0.5});
  test2<double,float,Minus>(double{1.2},float{0.5});
  test2<float,double,Minus>(float{1.2},double{0.5});
  test2<float,float,Minus>(float{1.2},float{0.5});
  test2<double,double,Mult>(double{1.2},double{0.5});
  test2<double,float,Mult>(double{1.2},float{0.5});
  test2<float,double,Mult>(float{1.2},double{0.5});
  test2<float,float,Mult>(float{1.2},float{0.5});
  test2<double,double,Div>(double{1.2},double{0.5});
  test2<double,float,Div>(double{1.2},float{0.5});
  test2<float,double,Div>(float{1.2},double{0.5});
  test2<float,float,Div>(float{1.2},float{0.5});
  return EXIT_SUCCESS;
}


