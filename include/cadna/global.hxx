/*!
 * \file   global.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#ifndef _LIB_CADNA_GLOBAL_HXX_
#define _LIB_CADNA_GLOBAL_HXX_

#include "cadna/macros.hxx"

constexpr const unsigned int CADNA_DIV        = 0x1;
constexpr const unsigned int CADNA_MUL        = 0x2;
constexpr const unsigned int CADNA_POWER      = 0x4;
constexpr const unsigned int CADNA_MATH       = 0x8;
constexpr const unsigned int CADNA_BRANCHING  = 0x10;
constexpr const unsigned int CADNA_INTRINSIC  = 0x20;
constexpr const unsigned int CADNA_CANCEL     = 0x40;
constexpr const unsigned int CADNA_ALL        = 0xFFFFFFFF;

namespace cadna{

  CADNA_VISIBILITY_EXPORT void set_rnd_arr();
  CADNA_VISIBILITY_EXPORT void set_rnd_plinf();
  CADNA_VISIBILITY_EXPORT void set_rnd_moinf();
  CADNA_VISIBILITY_EXPORT void set_rnd_zero();

  CADNA_VISIBILITY_EXPORT void  init(int, unsigned int,
				     unsigned int,
				     unsigned int);
  CADNA_VISIBILITY_EXPORT void  init(int, unsigned int);
  CADNA_VISIBILITY_EXPORT void  init(int);

  CADNA_VISIBILITY_EXPORT void enable(unsigned int);
  CADNA_VISIBILITY_EXPORT void disable(unsigned int);

  /*!
   * The enum struct contains all the type if instabilities detected
   * by CADNA
   */
  enum struct instability_id{
    MATH_INSTABILITY,
    CANCEL_INSTABILITY,
    DIV_INSTABILITY,
    MUL_INSTABILITY,
    POWER_INSTABILITY,
    INTRINSIC_INSTABILITY,
    BRANCHING_INSTABILITY
  }; // end of enum struct instability_id

  //! a simple alias used for handlers managements
  using handler_id = unsigned long; 
  
  struct Counter
  {
    unsigned long math_count      = 0u; 
    unsigned long cancel_count    = 0u;  
    unsigned long div_count       = 0u;
    unsigned long mul_count       = 0u;
    unsigned long power_count     = 0u;
    unsigned long intrinsic_count = 0u;  
    unsigned long branching_count = 0u;
    // destructor
    ~Counter();
  }; // end of struct Counter

  struct Config
  {
    // constructor
    Config();
    unsigned int div_tag=1;
    unsigned int mul_tag=1;
    unsigned int power_tag=1;
    unsigned int math_tag=1;
    unsigned int intrinsic_tag=1;
    unsigned int cancel_tag=1;
    unsigned int branching_tag=1;
    unsigned int div_change=0;
    unsigned int mul_change=0;
    unsigned int power_change=0;
    unsigned int math_change=0;
    unsigned int intrinsic_change=0;
    unsigned int cancel_change=0;
    unsigned int branching_change=0;
  };
  
  CADNA_VISIBILITY_EXPORT extern Counter counter;
  CADNA_VISIBILITY_EXPORT extern Config  config;
  
  CADNA_VISIBILITY_EXPORT extern int _cancel_value;
  
  CADNA_VISIBILITY_EXPORT extern unsigned int _random;
  CADNA_VISIBILITY_EXPORT extern int _max_instability;
  CADNA_VISIBILITY_EXPORT extern int _instability_detected;

  CADNA_VISIBILITY_EXPORT extern int          _random_counter;
  CADNA_VISIBILITY_EXPORT extern unsigned int _recurrence;

#ifdef _OPENMP
#pragma omp threadprivate (_random, _random_counter, _recurrence)
#endif //_OPENMP
  
} // end of namespace cadna

#endif /* _LIB_CADNA_GLOBAL_HXX_ */
