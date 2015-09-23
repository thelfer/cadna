/*!
 * \file   random.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   12 sept. 2015
 */

#ifndef _LIB_CADNA_RANDOM_HXX_
#define _LIB_CADNA_RANDOM_HXX_

#include"cadna/macros.hxx"
#include"cadna/global.hxx"

namespace cadna{
  
  inline unsigned int
  _TauswortheStep(const unsigned int,
			const unsigned int,
			const unsigned int,
			const unsigned int) CADNA_ALWAYS_INLINE;

  inline unsigned int
  _LCGStep(const unsigned int,
		 const unsigned int) CADNA_ALWAYS_INLINE;

  unsigned int _random_function() CADNA_ALWAYS_INLINE;
  
  inline unsigned int _TauswortheStep(const unsigned int s1,
					    const unsigned int s2,
					    const unsigned int s3,
					    const unsigned int m){
    const unsigned int b = (((_recurrence << s1) ^ _recurrence) >> s2);
    return _recurrence = (((_recurrence & m) << s3) ^ b);
  }
    
  inline unsigned int _LCGStep(const unsigned int a,
				     const unsigned int c){
    return _recurrence = (a * _recurrence + c);
  }

  inline unsigned int _random_function(){
    constexpr unsigned int Taus1S1 = 13;
    constexpr unsigned int Taus1S2 = 19;
    constexpr unsigned int Taus1S3 = 12;
    constexpr unsigned int Taus1M  = 429496729U;
    constexpr unsigned int Taus2S1 = 2;
    constexpr unsigned int Taus2S2 = 25;
    constexpr unsigned int Taus2S3 = 4;
    constexpr unsigned int Taus2M  = 4294967288U;
    constexpr unsigned int Taus3S1 = 3;
    constexpr unsigned int Taus3S2 = 11;
    constexpr unsigned int Taus3S3 = 17;
    constexpr unsigned int Taus3M  = 429496280U;
    constexpr unsigned int LCGa    = 1664525;
    constexpr unsigned int LCGc    = 1013904223U;
    if((_random_counter&0x1F)==0){
      const unsigned int z1 = _TauswortheStep(Taus1S1, Taus1S2, Taus1S3, Taus1M);
      const unsigned int z2 = _TauswortheStep(Taus2S1, Taus2S2, Taus2S3, Taus2M);
      const unsigned int z3 = _TauswortheStep(Taus3S1, Taus3S2, Taus3S3, Taus3M);
      const unsigned int z4 = _LCGStep(LCGa, LCGc);
      _recurrence = (z1 ^ z2 ^ z3 ^ z4);
      _random = _recurrence;
    }
    else{
      _random>>=1;
    }
    _random_counter++;
    return _random&1;
  }

} // end of namespace cadna

#endif /* _LIB_CADNA_RANDOM_HXX_ */
