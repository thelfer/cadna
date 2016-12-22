/*!
 * \file   bindings/python/cadna.cxx
 * \brief    
 * \author Thomas Helfer
 * \date   20 déc. 2016
 */

#include<iostream>
#include<boost/python.hpp>
#include"cadna/numeric_type.hxx"

template<typename T>
static void declare_numeric_type(const char *n){
  using namespace boost::python;
  using boost::python::self_ns::str;
  using real = cadna::numeric_type<T>;

  class_<real>(n,init<>())
    .def(init<T>())
    .def(init<T,T,T>())
    .def(self+self)
    .def(self+T())
    .def(T()+self)
    .def(self-self)
    .def(self-T())
    .def(T()-self)
    .def(self*self)
    .def(self*T())
    .def(T()*self)
    .def(self/self)
    .def(self/T())
    .def(T()/self)
    .def(self<=self)
    .def(self<=T())
    .def(T()<=self)
    .def(self<self)
    .def(self<T())
    .def(T()<self)
    .def(self>=self)
    .def(self>=T())
    .def(T()>=self)
    .def(self>self)
    .def(self>T())
    .def(T()>self)
    .def_readwrite("x", &real::x)
    .def_readwrite("y", &real::y)
    .def_readwrite("z", &real::z)
    //    .def(pow(self,self))
    // .def(pow(self,other<real>))
    // .def(pow(self,other<T>))
    // .def(pow(T,other<real>))
    // .def(abs(self))
    .def(str(self))
    ;

  int  (*ptr1)(const real&) = cadna::nb_significant_digit;
  int  (*ptr2)(const real&) = cadna::approx_digit;
  bool (*ptr3)(const real&) = cadna::computedzero;
  bool (*ptr4)(const real&) = cadna::numericalnoise;
  
  def("nb_significant_digit",ptr1);
  def("approx_digit",ptr2);
  def("computedzero",ptr3);
  def("numericalnoise",ptr4);
  
}

BOOST_PYTHON_MODULE(cadna)
{
  declare_numeric_type<double>("double_st");
}
