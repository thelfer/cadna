include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

set(cadna_SOURCES
  global.cxx
  numeric_type.cxx
  to_string.cxx
  instability.cxx
  instability_handler.cxx)

#   setroundingmode.cxx)

# # type of architecture
# if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
#   # 64 bits
#   if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#     set(cadna_SOURCES rnd_x86_00_64.s ${cadna_SOURCES})
#   elseif(APPLE)
#     set(cadna_SOURCES rnd_x86_10_64.s ${cadna_SOURCES})
#   else()
#     message(FATAL_ERROR "unsupported architecure")
#   endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
# else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
#   # 32 bits
#   if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#     set(cadna_SOURCES rnd_x86_00_32.s ${cadna_SOURCES})
#   elseif(MINGW)
#     set(cadna_SOURCES rnd_x86_00_32.s ${cadna_SOURCES})
#   elseif(CYGWIN)
#     set(cadna_SOURCES rnd_x86_11_32.s ${cadna_SOURCES})
#   elseif(APPLE)
#     set(cadna_SOURCES rnd_x86_10_32.s ${cadna_SOURCES})
#   else()
#     message(FATAL_ERROR "unsupported architecure")
#   endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
# endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
    (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  set(cadna_SOURCES
    cmath_gnu.cxx ${cadna_SOURCES})
else((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
     (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  set(cadna_SOURCES
    cmath_other.cxx ${cadna_SOURCES})
endif((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
      (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))

cadna_library(cadna_cxx
  ${cadna_SOURCES})
