#!/usr/bin/env bash

fname="l$1.cpp"

touch $fname

echo "add_executable(l$1 $fname)" >> CMakeLists.txt

git add $fname

echo "#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main () {
    Solution s;
}" > $fname