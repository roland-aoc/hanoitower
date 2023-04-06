rm -rf build &&
mkdir build &&
cd build &&
cmake -G "Unix Makefiles" ../buildconf/all &&
cd .. &&
cmake --build build