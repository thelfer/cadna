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
  
  CADNA_INLINE unsigned int
  _TauswortheStep(const unsigned int,
		  const unsigned int,
		  const unsigned int,
		  const unsigned int) CADNA_ALWAYS_INLINE;

  CADNA_INLINE unsigned int
  _LCGStep(const unsigned int,
	   const unsigned int) CADNA_ALWAYS_INLINE;

  CADNA_INLINE unsigned int
  _random_function() CADNA_ALWAYS_INLINE;

} // end of namespace cadna

#include"cadna/random.ixx"

#endif /* _LIB_CADNA_RANDOM_HXX_ */
