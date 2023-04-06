rm -rf build &&
mkdir build &&
cd build &&
cmake -G Ninja ../buildconf/all &&
cd .. &&
cmake --build build