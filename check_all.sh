#! /usr/bin/env bash
# Exit if any error detected
set -e

pbuild=no
# cross compilation using mingw
wbuild=no
while getopts ":wj:" opt;
do
  case $opt in
    j) pbuild=yes;
       nbproc="$OPTARG";
      ;;
    w) wbuild=yes
      ;;
    \?)
      echo "$0 : invalid option '$OPTARG'" >&2
      echo "bailing out." >&2
      exit 1
      ;;
    :)
      echo "$0 : option '-$OPTARG' requires an argument." >&2
      echo "bailing out." >&2
      exit 1
      ;;
  esac
done

make_exec=make
if test "x$pbuild" == "xyes" ;
then
    make_exec="$make_exec -j $nbproc"
fi

# remove previous temporary
if [ -d build-check ];
then
    chmod +w -R build-check
    rm -fr build-check
fi

# source directory
src=$(dirname $(realpath $0))
# current directory
build=$(pwd)

# get the package name
pkg_name=$(cat $src/configure.ac|grep AC_INIT|awk 'BEGIN{FS=","} {print $2}')

mkdir build-check
pushd build-check
mkdir autotools
pushd autotools
mkdir install-autotools
mkdir install-autotools-debug
mkdir build-autotools
pushd build-autotools
$src/configure --prefix=$build/build-check/autotools/install-autotools 
$make_exec
$make_exec check
$make_exec distcheck
$make_exec install
popd # from build-autotools
mkdir build-autotools-debug
pushd build-autotools-debug
$src/configure --prefix=$build/build-check/autotools/install-autotools-debug 
$make_exec
$make_exec check
$make_exec distcheck
$make_exec install
popd # from build-autotools-debug
popd # from autotools

mkdir cmake
pushd cmake
tar -xvjf $build/build-check/autotools/build-autotools/cadna-$pkg_name.tar.bz2
mkdir install-cmake
mkdir build-cmake
mkdir install-cmake-release
mkdir build-cmake-release
mkdir install-cmake-debug
mkdir build-cmake-debug
pushd build-cmake
cmake ../cadna-$pkg_name/ -DCMAKE_INSTALL_PREFIX=$build/build-check/cmake/install-cmake
$make_exec 
if [ test "x$pbuild" == "xyes" ];
then
    make check ARGS="-j $nbproc"
else
    $make_exec check 
fi
$make_exec install
popd #from build-cmake
pushd build-cmake-release
cmake ../cadna-$pkg_name/ -DCMAKE_BUILD_TYPE=Release  -DCMAKE_INSTALL_PREFIX=$build/build-check/cmake/install-cmake-release
$make_exec
if [ test "x$pbuild" == "xyes" ];
then
    make check ARGS="-j $nbproc"
else
    $make_exec check 
fi
$make_exec install
popd #from build-cmake-release
pushd build-cmake-debug
cmake ../cadna-$pkg_name/ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$build/build-check/cmake/install-cmake-debug
$make_exec
if [ test "x$pbuild" == "xyes" ];
then
    make check ARGS="-j $nbproc"
else
    $make_exec check 
fi
$make_exec install
popd #from build-cmake-debug

if test "x$wbuild" == "xyes" ;
then
    if [ "x$(which i686-w64-mingw32-gcc)" != "x" ];
    then
	mkdir build-cmake-i686-w64-mingw32
	pushd build-cmake-i686-w64-mingw32
	cmake ../cadna-$pkg_name/  -DCMAKE_INSTALL_PREFIX=$build/build-check/cmake/install-cmake-i686-w64-mingw32 -DCMAKE_TOOLCHAIN_FILE=../cadna-$pkg_name/cmake/ToolChain-i686-w64-mingw32.cmake
	$make_exec
	if [ "x$(which wine)" != "x" ];
	then
	    if [ test "x$pbuild" == "xyes" ];
	    then
		make check ARGS="-j $nbproc"
	    else
		$make_exec check 
	    fi
	fi
	$make_exec install
	popd #from build-cmake-i686-w64-mingw32
    fi
    
    if [ "x$(which i586-mingw32msvc-gcc)" != "x" ];
    then
	mkdir build-cmake-i586-mingw32msvc
	pushd build-cmake-i586-mingw32msvc
	cmake ../cadna-$pkg_name/ -DCMAKE_INSTALL_PREFIX=$build/build-check/cmake/install-cmake-i586-mingw32msvc -DCMAKE_TOOLCHAIN_FILE=../cadna-$pkg_name/cmake/ToolChain-i586-mingw32msvc.cmake
	$make_exec
	if [ "x$(which wine)" != "x" ];
	then
	    if [ test "x$pbuild" == "xyes" ];
	    then
		make check ARGS="-j $nbproc"
	    else
		$make_exec check 
	    fi
	fi
	$make_exec install
	popd #from build-cmake-i586-mingw32msvc
    fi
fi

popd #from cmake
popd #from build-check

