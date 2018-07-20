#!/bin/bash

cd build
ln -s bufferedreader br
g++ -Ofast -Wall ../src/*.cpp -o bufferedreader
