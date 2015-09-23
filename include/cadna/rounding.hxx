// Copyright 2015 J.-M. Chesneaux, P. Eberhart, F. Jezequel, J.-L. Lamotte

// This file is part of CADNA.

// CADNA is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// CADNA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License
// along with CADNA.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __CADNA_RND_H__
#define __CADNA_RND_H__

#include"cadna/macros.hxx"

namespace cadna{

  CADNA_VISIBILITY_EXPORT void
  set_rnd_arr(void) noexcept;

  CADNA_VISIBILITY_EXPORT void
  set_rnd_plinf(void) noexcept;

  CADNA_VISIBILITY_EXPORT void
  set_rnd_moinf(void) noexcept;
  
  CADNA_VISIBILITY_EXPORT void
  set_rnd_zero(void) noexcept;

} // end of namespace cadna

#endif
