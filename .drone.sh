#!/bin/bash

echo "Build Server Setup..."
sudo apt-add-repository ppa:ubuntu-toolchain-r/test # gcc-5
sudo apt-add-repository ppa:george-edison55/precise-backports # doxygen, cmake
sudo apt-add-repository ppa:beineri/opt-qt551 # qtbase5-dev
sudo apt-get update
sudo apt-get install qt55base qt55declarative
export PATH="/opt/qt55/bin:$PATH"
sudo apt-get --no-install-recommends install gcc-5 g++-5 cmake doxygen valgrind
echo 2 | sudo update-alternatives --config gcc
export CXX="g++-5" CC="gcc-5";

echo "Build Server Info..."
echo "$PATH"
cmake --version
qmake --version
gcc --version

echo "Configure..."
mkdir build && cd build
cmake ..

echo "Compile..."
make VERBOSE=1
