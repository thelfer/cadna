set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -std=c++11")

cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "Wall")
# 383 : value copied to temporary, reference to temporary used
# 981 : operands are evaluated in unspecified order
# 810 : conversion from "long double" to "double" may lose significant bits
# 1418: external function definition with no prior declaration
# 444 : destructor for base class is not virtual
# 1565: attributes are ignored on a class declaration that is not also a definition
cadna_check_cxx_compiler_flag("-diag-disable 981" DIAG_DISABLE_FLAG_AVAILABLE)
if(${DIAG_DISABLE_FLAG_AVAILABLE})
  message(STATUS "enabling flag '-diag-disable'")
  set(COMPILER_WARNINGS "-diag-disable 981,383,810,1418,444,2259,1565 ${COMPILER_WARNINGS}")
else(${DIAG_DISABLE_FLAG_AVAILABLE})
  message(STATUS "flag '-diag-disable' disabled")
endif(${DIAG_DISABLE_FLAG_AVAILABLE})

cadna_enable_cxx_compiler_flag(OPTIMISATION_FLAGS_MARCH "xHost")
cadna_enable_cxx_compiler_flag(CMAKE_CXX_FLAGS    "ipo")

cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility=hidden")
cadna_enable_cxx_compiler_flag(VISIBILITY_FLAGS "fvisibility-inlines-hidden")

if((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL "Release"))
  set(OPTIMISATION_FLAGS "-O3 -DNDEBUG ${OPTIMISATION_FLAGS}")
endif((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL "Release"))

set(COMPILER_CXXFLAGS "${COMPILER_CXXFLAGS} -frounding-math")
set(CADNA_COMPILER_CXXFLAGS "-frounding-math")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions("-g")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
