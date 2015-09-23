/*!
 * \file   setroundingmode.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   18 sept. 2015
 */

#include"cadna/rounding.hxx"

extern "C" void rnd_arr(void);
extern "C" void rnd_moinf(void);
extern "C" void rnd_plinf(void);
extern "C" void rnd_zero(void);
extern "C" void rnd_switch(void);

namespace cadna{

  void set_rnd_arr() noexcept
  {
    rnd_arr();
  }

  void set_rnd_plinf() noexcept
  {
    rnd_plinf();
  }

  void set_rnd_moinf() noexcept
  {
    rnd_moinf();
  }
  
  void set_rnd_zero() noexcept
  {
    rnd_zero();
  }

} // end of namespace cadna

