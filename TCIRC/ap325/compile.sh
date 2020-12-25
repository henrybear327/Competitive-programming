#/bin/sh

PROBLEM=$1

clang-format -i -style=LLVM *.cpp
astyle --style=linux *.cpp 
rm *.orig
compiler='/usr/local/Cellar/gcc/10.2.0/bin/g++-10'
$compiler -Wall -Wextra -Wshadow -std=c++14 -fanalyzer $PROBLEM.cpp
