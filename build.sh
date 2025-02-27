#!/bin/sh

if [ -d "cmake-build" ]; then
  cd cmake-build
else
    mkdir cmake-build
    cd cmake-build
fi

cmake ../CMakeLists.txt  -G"Unix Makefiles"