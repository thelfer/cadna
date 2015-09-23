## Makefile.am -- Process this file with automake to produce a Makefile.in file.
AM_CPPFLAGS = -I$(top_builddir)/cadna-config \
	      -I$(top_srcdir)/include

bin_PROGRAMS = cadna-config
cadna_config_SOURCES  = cadna-config.cxx               
cadna_config_CPPFLAGS = $(AM_CPPFLAGS) -Dcadna_cxx_EXPORTS
cadna_config_CXXFLAGS = -O3 -g -Wunused -frounding-math -std=c++11
EXTRA_DIST = CMakeLists.txt
