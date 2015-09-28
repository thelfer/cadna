# Find the libunwind library
# macros found here:
# https://github.com/cmccabe/lksmith/blob/master/cmake_modules/FindLibunwind.cmake
#
#  CADNA_LIBUNWIND_FOUND       - True if libunwind was found.
#  CADNA_LIBUNWIND_LIBRARIES   - The libraries needed to use libunwind
#  CADNA_LIBUNWIND_INCLUDE_DIR - Location of unwind.h and libunwind.h


FIND_PATH(CADNA_LIBUNWIND_INCLUDE_DIR libunwind.h)
if(CADNA_LIBUNWIND_INCLUDE_DIR)
  if(NOT EXISTS "${CADNA_LIBUNWIND_INCLUDE_DIR}/unwind.h")
    message(FATAL_ERROR "libunwind.h was found, but unwind.h was not found in that directory.")
    SET(CADNA_LIBUNWIND_INCLUDE_DIR "")
  endif()
  
  FIND_LIBRARY(CADNA_LIBUNWIND_GENERIC_LIBRARY "unwind")
  if (NOT CADNA_LIBUNWIND_GENERIC_LIBRARY)
    MESSAGE(FATAL_ERROR "failed to find unwind generic library")
  endif ()
  SET(CADNA_LIBUNWIND_LIBRARIES ${CADNA_LIBUNWIND_GENERIC_LIBRARY})
  
  # For some reason, we have to link to two libunwind shared object files:
  # one arch-specific and one not.
  if (CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
    SET(CADNA_LIBUNWIND_ARCH "arm")
  elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64")
    SET(CADNA_LIBUNWIND_ARCH "x86_64")
  elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$")
    SET(CADNA_LIBUNWIND_ARCH "x86")
  endif()
  
  if (CADNA_LIBUNWIND_ARCH)
    FIND_LIBRARY(CADNA_LIBUNWIND_SPECIFIC_LIBRARY "unwind-${CADNA_LIBUNWIND_ARCH}")
    if (NOT CADNA_LIBUNWIND_SPECIFIC_LIBRARY)
      MESSAGE(FATAL_ERROR "failed to find unwind-${CADNA_LIBUNWIND_ARCH}")
    endif ()
    SET(CADNA_LIBUNWIND_LIBRARIES ${CADNA_LIBUNWIND_LIBRARIES} ${CADNA_LIBUNWIND_SPECIFIC_LIBRARY})
  endif(CADNA_LIBUNWIND_ARCH)
  MESSAGE(STATUS "found unwind.h  : ${CADNA_LIBUNWIND_INCLUDE_DIR}/unwind.h")
  MESSAGE(STATUS "found libunwind : ${CADNA_LIBUNWIND_LIBRARIES}")
  MARK_AS_ADVANCED(CADNA_LIBUNWIND_LIBRARIES CADNA_LIBUNWIND_INCLUDE_DIR)
  set(CADNA_LIBUNWIND_FOUND ON)
  add_definitions("-DCADNA_HAVE_LIBUNWIND")
else ()
  MESSAGE(STATUS "libunwind not found")
  set(CADNA_LIBUNWIND_FOUND OFF)
endif()
  
