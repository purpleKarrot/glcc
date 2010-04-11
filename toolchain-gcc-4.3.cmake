
# gcc 4.4 has some bugs in ubuntu 10.04
# cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-gcc-4.3.cmake ..

set(CMAKE_C_COMPILER   gcc-4.3)
set(CMAKE_CXX_COMPILER g++-4.3)
