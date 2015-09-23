/*!
 * \file   macros.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   14 sept. 2015
 */

#ifndef _LIB_CADNA_CONFIG_HXX_
#define _LIB_CADNA_CONFIG_HXX_

#define CADNA_ALWAYS_INLINE __attribute__((always_inline))
#if __cplusplus >= 201402L
// This macro is used for non const member, which is supported by
// C++14 and not C++11
#define CADNA_CONSTEXPR constexpr
#else
#define CADNA_CONSTEXPR inline
#endif

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
#endif /* LIB_CADNA_CONFIG_HXX_ */

#endif /* _LIB_CADNA_CONFIG_HXX_ */
