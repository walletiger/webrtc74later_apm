rm -fr build
mkdir build 
cd build 
cmake  -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=$PWD/../../_install  ../
make -j8
make install -j8
