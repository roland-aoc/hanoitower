rm -rf build &&
mkdir build &&
cd build &&
cmake -G Ninja ../buildconf/testonly &&
cd .. &&
cmake --build build