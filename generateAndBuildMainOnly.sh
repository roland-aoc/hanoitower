rm -rf build &&
mkdir build &&
cd build &&
cmake -G Ninja ../buildconf/mainonly &&
cd .. &&
cmake --build build