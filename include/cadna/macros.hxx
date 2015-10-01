/*!
 * \file   macros.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#ifndef _LIB_CADNA_CONFIG_HXX_
#define _LIB_CADNA_CONFIG_HXX_

// October 2015 : a simple trick: including this header has not effect
// in c++ other than defining some macros specific to the standard
// library implementation: here we want to detect if we use libc++
// \see the definition of the CADNA_BEGIN_NAMESPACE_STD and
// CADNA_END_NAMESPACE_STD macros
#include<ciso646>

#ifdef __GNUC__
#ifndef __INTEL_COMPILER
#define CADNA_ALWAYS_INLINE __attribute__((always_inline))
#endif
#endif
#ifdef __INTEL_COMPILER
#define CADNA_INLINE __forceinline inline
#endif
#ifndef CADNA_INLINE
#define CADNA_INLINE inline
#endif
#ifndef CADNA_ALWAYS_INLINE
#define CADNA_ALWAYS_INLINE
#endif

#if __cplusplus >= 201402L
// This macro is used for non const member, which is supported by
// C++14 and not C++11
#define CADNA_CONSTEXPR constexpr
#else
#define CADNA_CONSTEXPR inline
#endif

#ifdef CADNA_HAVE_NORETURN_ATTRIBUTE
#define CADNA_NORETURN [[ noreturn ]]
#else
#define CADNA_NORETURN
#endif /* CADNA_HAVE_NORETURN_ATTRIBUTE */

#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
#define CADNA_IMPORT __declspec(dllimport)
#define CADNA_EXPORT __declspec(dllexport)
#define CADNA_LOCAL
#else /* defined _WIN32 || defined __CYGWIN__ */
#if (defined __GNUC__) && (! defined __INTEL_COMPILER)
#if __GNUC__ >= 4
#define CADNA_IMPORT __attribute__((visibility("default")))
#define CADNA_EXPORT __attribute__((visibility("default")))
#define CADNA_LOCAL  __attribute__((visibility("hidden")))
#else /*__GNUC__ >= 4 */
#define CADNA_IMPORT
#define CADNA_EXPORT
#define CADNA_LOCAL
#endif /* LIB_CADNA_CONFIG_HXX_ */
#elif defined __INTEL_COMPILER
#define CADNA_IMPORT __attribute__((visibility("default")))
#define CADNA_EXPORT __attribute__((visibility("default")))
#define CADNA_LOCAL  __attribute__((visibility("hidden")))
#else 
#define CADNA_IMPORT
#define CADNA_EXPORT
#define CADNA_LOCAL
#endif /* LIB_CADNA_CONFIG_HXX_ */
#endif /* LIB_CADNA_CONFIG_HXX_ */

/*!
 * defining macros by librairies using cmake conventions.
 * When compiling libfoo, cmake defines the macro foo_EXPORTS.
 * This allows to distinguish import/export definitions of symbols
 */
#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
#  if defined cadna_cxx_EXPORTS
#    define CADNA_VISIBILITY_EXPORT CADNA_EXPORT
#  else
#  ifndef CADNA_STATIC_BUILD
#    define CADNA_VISIBILITY_EXPORT CADNA_IMPORT
#  else 
#    define CADNA_VISIBILITY_EXPORT 
#  endif
#  endif
#else
#  define CADNA_VISIBILITY_EXPORT CADNA_EXPORT
#endif

#if (defined _LIBCPP_VERSION)
#define CADNA_BEGIN_NAMESPACE_STD _LIBCPP_BEGIN_NAMESPACE_STD
#else
#define CADNA_BEGIN_NAMESPACE_STD namespace std{
#endif
#if (defined _LIBCPP_VERSION)
#define CADNA_END_NAMESPACE_STD _LIBCPP_END_NAMESPACE_STD
#else
#define CADNA_END_NAMESPACE_STD }
#endif

#endif /* _LIB_CADNA_CONFIG_HXX_ */
