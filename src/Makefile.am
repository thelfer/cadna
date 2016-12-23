AM_CXXFLAGS = 
AM_CPPFLAGS = -I$(top_srcdir)/include   \
	      -I$(top_srcdir)/src

lib_LTLIBRARIES  = libcadna_cxx.la

libcadna_cxx_la_SOURCES= cmath_specific.cxx      \
                         global.cxx              \
                         numeric_type.cxx        \
	                 to_string.cxx           \
	                 instability.cxx         \
	                 instability_handler.cxx \
			 setroundingmode.cxx     \
			 logstream.cxx           \
			 backtrace.cxx

libcadna_cxx_la_CPPFLAGS = $(AM_CPPFLAGS) -Dcadna_cxx_EXPORTS
libcadna_cxx_la_CXXFLAGS = -O3 -g -Wunused -frounding-math -std=c++11

nodist_libcadna_cxx_la_SOURCES = rounding.s 
EXTRA_libcadna_cxx_la_SOURCES  = cmath_other.cxx       \
				 cmath_gnu.cxx         \
				 cmath_common-impl.cxx \
				 rnd_ppc_aix.s         \
				 rnd_ia64.s            \
				 rnd_sun.s             \
				 rnd_x86_00_32.s       \
				 rnd_x86_00_64.s       \
				 rnd_x86_10_32.s       \
				 rnd_x86_11_32.s       \
				 rnd_x86_10_64.s       \
				 rnd_x86mac_10_64.s

EXTRA_DIST = CMakeLists.txt
