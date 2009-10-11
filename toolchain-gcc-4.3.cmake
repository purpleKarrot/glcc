
# gcc 4.4.1 has problems with GIL, so in the meantime we use gcc 4.3
# cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-gcc-4.3.cmake ..

set(CMAKE_C_COMPILER   gcc-4.3)
set(CMAKE_CXX_COMPILER g++-4.3)
