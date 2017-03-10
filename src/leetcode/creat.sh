#!/usr/bin/env bash

fname="l$1.cpp"

touch $fname

echo "add_executable(l$1 $fname)" >> CMakeLists.txt

git add $fname