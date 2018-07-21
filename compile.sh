#!/bin/bash

mkdir build 2>/dev/null
cd build || exit 1

rm -f br
rm -f bufferedreader

g++ -Ofast -Wall ../src/*.cpp -o bufferedreader
ln -s bufferedreader br 2>/dev/null
