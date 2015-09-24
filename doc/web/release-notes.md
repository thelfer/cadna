% Release notes of CADNA
% Helfer Thomas, Jezequel Fabienne
% 24/09/2015

# Releases notes of version 3.0

Version 3.0 of `CADNA` is a rewrite of the library to match the
quality requirements of the CEA `PLEIADES` platform.

## New features

- `CADNA` data structures and functions have their own namespace named
  `cadna`. However, the `cadna.h` header is provided for backward
  compatiblity and inject in the anonymous namespace some `cadna`
  function provided by previous versions of the library.
- All `CADNA` headers are now in a separate directory named `cadna`,
  except a `cadna.h` header which is provided for backward
  compatiblity.
- `cadna_init` and `cadna_end` (defined in `cadna.h`) are no more
  needed and are provided for backward compatibility:
    - `cadna_end` is now an empty function provided for backward
	  compatibility.
	- `cadna_init` is replaced by the `cadna::init` function. If
      default values are sufficient, call to `cadna::init` is
      unnecessary. For modifying the default behaviour of the library,
      users may consider using environment variables
- Support for `runtime` configuration using environment variables. The
  following environment variables are checked at runtime: `CADNA_DIV`,
  `CADNA_MUL`, `CADNA_MATH`, `CADNA_POWER`, `CADNA_INTRINSIC`,
  `CADNA_CANCEL` and `CADNA_BRANCHING`. For example, if `CADNA_DIV` is
  set to `DISABLED`, instabilities du to divisions between `CADNA`
  number are not treated.
- More C++-11 standard compliant implementation:
    - Most `cmath` function are supported.
    - Specialization of class `std::numeric_limits` for `CADNA` types
      are provided.
	- overloading of function `std::to_string` for `CADNA` types are
      provided.
- Introduction of `instability_handlers`:
    - instability handlers allow the user to specifiy what happens if
      an instability occurs.
- Add the `cadna-config` executable:
    - `cadna-config --includes` returns the path to `CADNA` headers.
    - `cadna-config --libs` returns the path to the `CADNA` library.
	- `cadna-config --cxxflags` returns the flags required to use the
      `CADNA` library.
	- other options may be found using `cadna-config --help`
- (`cmake`)[http://cmake.org/] build system

## Deprecated features

- Usage of `cadna.h` is discouraged.

## Supported plate-forms

Version 3.0.x was tested using the following compilers:

- [`gcc`](https://gcc.gnu.org/)
- [`clang`](http://clang.llvm.org/)
- [`mingw`](http://www.mingw.org/)
- [`mingw`](http://www.mingw.org/)

- [`Visual Studio`](https://www.visualstudio.com/)
- [`cygwin`](https://www.visualstudio.com)

<!-- Local IspellDict: english -->
