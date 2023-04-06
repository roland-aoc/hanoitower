rm -rf build &&
mkdir build &&
cd build &&
cmake -G "Unix Makefiles" ../buildconf/mainonly &&
cd .. &&
cmake --build build