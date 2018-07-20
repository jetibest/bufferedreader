#!/bin/bash

mkdir build 2>/dev/null
cd build
ln -s bufferedreader br
g++ -Ofast -Wall ../src/*.cpp -o bufferedreader
