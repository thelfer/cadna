/*!
 * \file   global.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#include<fenv.h>
#include<iostream>

#ifdef _OPENMP
#include <omp.h>
#endif //_OPENMP

#include"cadna/global.hxx"
#include"cadna/random.hxx"

namespace cadna{

#ifndef PACKAGE_STRING
  const char* PACKAGE_STRING = "CADNA";
#endif
  
  //=====================================================
  //   "CADNA_INIT"
  //=====================================================

  //  global variables


  // INSTABILITIES MANAGEMENT
  int _max_instability, _instability_detected;
  int nb_stability_count = 0;

  Counter counter;
  Config config;

  int _cancel_value=4;

  // The RANDOM BIT GENERATOR
  
  unsigned int _random;
  int          _random_counter;
  unsigned int _recurrence;

  const char* _div_err_msg       = "UNSTABLE DIVISION(S)";
  const char* _mul_err_msg       = "UNSTABLE MULTIPLICATION(S)";
  const char* _power_err_msg     = "UNSTABLE POWER FUNCTION(S)";
  const char* _branching_err_msg = "UNSTABLE BRANCHING(S)";
  const char* _cancel_err_msg    = "LOSS(ES) OF ACCURACY DUE TO CANCELLATION(S)";
  const char* _intrinsic_err_msg = "UNSTABLE INTRINSIC FUNCTION(S)";
  const char* _math_err_msg      = "UNSTABLE MATHEMATICAL FUNCTION(S)";

  enum struct InitialisationStatus{
    FIRSTCALL,
    OTHERCALL
  };
    
  static void init(int max_instability, unsigned int tag,
		   unsigned int seed, unsigned int cancellation,
		   const InitialisationStatus status)
  {
    using namespace std;
    _cancel_value=cancellation;
  
    _max_instability=max_instability;
    _instability_detected=0;
  
    counter.div_count=0;
    counter.mul_count=0;  
    counter.power_count=0;  
    counter.math_count=0; 
    counter.intrinsic_count=0;  
    counter.cancel_count=0;  
    counter.branching_count=0; 
    
    if ( max_instability == 0){
      config.div_change=1; 
      config.mul_change=1;  
      config.power_change=1;  
      config.branching_change=1;
      config.cancel_change=1; 
      config.intrinsic_change=1; 
      config.math_change=1;
      config.div_tag=0; 
      config.mul_tag=0;  
      config.power_tag=0;  
      config.branching_tag=0;
      config.cancel_tag=0; 
      config.intrinsic_tag=0; 
      config.math_tag=0; 
    } else {
      if (tag & CADNA_DIV)   {
	config.div_tag=0; 
	config.div_change=1; 
      }
      if (tag & CADNA_MUL) {
	config.mul_tag=0; 
	config.mul_change=1; 
      }
      if (tag & CADNA_POWER) {
	config.power_tag=0; 
	config.power_change=1; 
      }
      if (tag & CADNA_MATH) {
	config.math_tag=0; 
	config.math_change=1; 
      }
      if (tag & CADNA_INTRINSIC) {
	config.intrinsic_tag=0; 
	config.intrinsic_change=1; 
      }
      if (tag & CADNA_CANCEL) {
	config.cancel_tag=0; 
	config.cancel_change=1; 
      }
      if (tag & CADNA_BRANCHING) {
	config.branching_tag=0; 
	config.branching_change=1; 
      }
    }

    if(status==InitialisationStatus::FIRSTCALL){
      cout << "----------------------------------------------------------------" << endl;
      cout << PACKAGE_STRING << " software --- University P. et M. Curie --- LIP6" << endl;
      cout << "----------------------------------------------------------------" << endl;
    } else {
      cout << "----------------------------------------------------------------" << endl;
      if (config.div_tag & config.mul_tag & config.power_tag){
	cout << "Self-validation detection: ON" << endl;
      } else {
	cout << "Self-validation detection: OFF" << endl;
      }
      cout << "Mathematical instabilities detection: " <<  (config.math_tag ? "ON": "OFF") << endl;
      cout << "Branching instabilities detection: " << (config.branching_tag ? "ON": "OFF") << endl;
      cout << "Intrinsic instabilities detection: " << (config.intrinsic_tag ? "ON": "OFF") << endl;
      cout << "Cancellation instabilities detection: " << (config.cancel_tag ? "ON": "OFF") << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
#ifdef _OPENMP
#pragma omp parallel shared(seed)
    {
      _recurrence=omp_get_thread_num()*1099087573UL+seed;
      _random=0;
      _random_counter=0;
    }
#pragma omp barrier
#else //_OPENMP
    _recurrence+=seed;
    _random=0;
    _random_counter=0;
#endif //_OPENMP
    
  }

  void init(int max_nb_instability) 
  {
    init(max_nb_instability,0,51,_cancel_value);
  }

  void init(int max_nb_instability,unsigned int tag) 
  {
    init(max_nb_instability,tag,51,_cancel_value);
  }

  void init(int max_instability, unsigned int tag, unsigned int seed, unsigned int cancellation){
    init(max_instability,tag,seed,cancellation,InitialisationStatus::OTHERCALL);
  }

  Config::Config(){
    // call the init function with default values
    init(-1,0,51,_cancel_value,InitialisationStatus::FIRSTCALL);
    // unsigned int rounding_mode=fegetround();
    // cout << rounding_mode << endl;
    fesetround(FE_UPWARD);
    // rounding_mode=fegetround();
    // cout << rounding_mode << endl;
#ifdef _OPENMP
    unsigned int rounded_up;
#pragma omp parallel reduction(&&:rounded_up)
    {
      // unsigned int local_rounding_mode=fegetround();
      // cout << local_rounding_mode << endl;
      // double test = 1.;
      // rounded_up = 1;
      // test += 1.e-20;
      // cout << test << endl;
      // if (test != 1.)
      //   rounded_up = 0;
      rounded_up = (fegetround() == FE_UPWARD);
    }
#pragma omp barrier
    if (!rounded_up) {
#pragma omp parallel
      {
	fesetround(FE_UPWARD);
      }
#pragma omp barrier
#pragma omp parallel reduction(&&:rounded_up)
      {
	// unsigned int local_rounding_mode=fegetround();
	// cout << local_rounding_mode << endl;
	// double test = 1.;
	// rounded_up = 1;
	// test += 1.e-20;
	// cout << test << endl;
	// // if (test != 1.)
	// //   rounded_up = 0;
	rounded_up = (fegetround() == FE_UPWARD);
      }
#pragma omp barrier
      if (!rounded_up) {
	cout << "Implementation of OpenMP incompatible with this version of CADNA" << endl;
	// exit(-1);
      }
    }
#endif //_OPENMP
  }
  
  Counter::~Counter()
  {
    using namespace std;
    fesetround(FE_TONEAREST);
  
    cout << "----------------------------------------------------------------" << endl;
    cout << PACKAGE_STRING << " software --- University P. et M. Curie --- LIP6" << endl;
    unsigned long long sum= this->div_count+this->mul_count+this->math_count+this->power_count +
      this->intrinsic_count+this->cancel_count+this->branching_count;
  
    if (!sum){
      cout << "No instability detected" << endl;
    } else {
      if (this->div_count+this->mul_count+this->power_count){
	cout << endl;
	cout <<  "CRITICAL WARNING: the self-validation detects major problem(s)." << endl;
	cout << "The results are NOT guaranteed." << endl ;
	cout << endl;
      } else if (config.div_change || config.mul_change || config.power_change){
	cout << endl;
	cout << "BE CAREFUL: the self-validation has been deactivated." << endl;
	cout << "The results are NOT guaranteed." << endl ;
	cout << endl;
      }
    
      if (sum==1){
	cout << "There is  1 numerical instability" << endl;
      } else{
	cout << "There are " << sum << " numerical instabilities" << endl;
      }
    
      if  (config.div_tag && this->div_count) 
	cout <<  this->div_count << " " <<  _div_err_msg << endl;
      if  (config.mul_tag && this->mul_count) 
	cout <<  this->mul_count << " " <<  _mul_err_msg << endl;
      if  (config.power_tag && this->power_count) 
	cout <<  this->power_count << " " <<  _power_err_msg << endl;
      if  (config.branching_tag && this->branching_count) 
	cout <<  this->branching_count << " " <<  _branching_err_msg << endl;
      if (config.intrinsic_tag && this->intrinsic_count) 
	cout <<  this->intrinsic_count << " " <<  _intrinsic_err_msg << endl;
      if  (config.math_tag && this->math_count) 
	cout <<  this->math_count << " " <<  _math_err_msg << endl;
      if  (config.cancel_tag && this->cancel_count) 
	cout <<  this->cancel_count << " " <<  _cancel_err_msg << endl;
    }
    cout << "----------------------------------------------------------------" << endl;

  }


  //****f* type/enable
  //    NAME
  //     enable
  //
  //    SYNOPSIS
  //      void enable(unsigned int tag)
  //    FUNCTION
  //      The enable function enables the detection of a kind of
  //      numerical instability.
  //    INPUTS
  //      unsigned int tag (see documentation)
  //    RESULT
  //      
  //    SEE ALSO
  //        disable(3)
  //*****
  //   You can use this space for remarks that should not be included
  //   in the documentation.
  //    EXAMPLE
  //      
  //  
  //    NOTES
  //  
  //  
  //    BUGS
  //  
  //  
  //      
  //      
  //  /


  void enable(unsigned int tag)
  {
    using namespace std;
    if (_max_instability==-2) {
      cerr << "-----------------------------------------------------------" << endl;
      cerr << " CADNA: The maximum number of instabilities has been reached" << endl;
      cerr << " The select_instability is not performed"    << endl;
      cerr << "-----------------------------------------------------------" << endl;
    }
  
    if (tag & CADNA_DIV)  { 
      if (!config.div_tag) config.div_change=1;
      config.div_tag=1;
    }
  
    if (tag & CADNA_MUL)  { 
      if (!config.mul_tag) config.mul_change=1;
      config.mul_tag=1;
    }

    if (tag & CADNA_POWER)  { 
      if (!config.power_tag) config.power_change=1;
      config.power_tag=1;
    }
  
    if (tag & CADNA_BRANCHING){ 
      if (!config.branching_tag) config.branching_change=1;
      config.branching_tag=1;
    }
  
    if (tag & CADNA_CANCEL){ 
      if (!config.cancel_tag) config.cancel_change=1;
      config.cancel_tag=1;
    }
  
    if (tag & CADNA_INTRINSIC){ 
      if (!config.intrinsic_tag) config.intrinsic_change=1;
      config.intrinsic_tag=1;
    }
  
    if (tag & CADNA_MATH){ 
      if (!config.math_tag) config.math_change=1;
      config.math_tag=1;
    }
  }

  void disable(unsigned int tag)
  {
    if (tag & CADNA_DIV){ 
      if (config.div_tag) config.div_change=1;
      config.div_tag=0;
    }
  
    if (tag & CADNA_MUL){ 
      if (config.mul_tag) config.mul_change=1;
      config.mul_tag=0;
    }

    if (tag & CADNA_POWER){ 
      if (config.power_tag) config.power_change=1;
      config.power_tag=0;
    }
  
    if (tag & CADNA_BRANCHING){ 
      if (config.branching_tag) config.branching_change=1;
      config.branching_tag=0;
    }

    if (tag & CADNA_CANCEL){ 
      if (config.cancel_tag) config.cancel_change=1;
      config.cancel_tag=0;
    }
  
    if (tag & CADNA_INTRINSIC){ 
      if (config.intrinsic_tag) config.intrinsic_change=1;
      config.intrinsic_tag=0;
    }
  
    if (tag & CADNA_MATH){ 
      if (config.math_tag) config.math_change=1;
      config.math_tag=0;
    }
  }

} // end of namespace cadna
