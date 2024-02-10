#!/bin/bash -x

#create the build directory
mkdir -p build-unix

#go to the directory
cd build-unix

#cmake will check if the compiler, C++ libraries, etc. are correct in your system and generate the necessary files to compile the code
cmake -DCMAKE_CXX_COMPILER=g++-12 -DCMAKE_C_COMPILER=gcc-12 ../

#cmake will compile the code and build the executable
cmake --build ./

#we run the program now
./a1-program
