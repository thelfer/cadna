AM_CPPFLAGS = -I@top_srcdir@/include/                       \
	      @BOOST_CPPFLAGS@                              \
	      -I@PYTHONPATH@/include/python@PYTHON_VERSION@

cadnadir = @pythondir@
cadna_LTLIBRARIES = cadna.la
cadna_la_SOURCES  = cadna.cxx
cadna_la_LIBADD   = @BOOST_LIBS@ @BOOST_PYTHON_LIBS@            \
		    -L@PYTHONPATH@/lib -lpython@PYTHON_VERSION@
cadna_la_LDFLAGS  = -module
cadna_la_CXXFLAGS = -O3 -Wunused -frounding-math -std=c++11

EXTRA_DIST=CMakeLists.txt
