#/bin/sh

PROBLEM=$1

clang-format -i -style=LLVM $PROBLEM.cpp
astyle --style=linux $PROBLEM.cpp 
rm *.orig
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	echo 'linux'
	compiler='g++'
elif [[ "$OSTYPE" == "darwin"* ]]; then
	echo 'darwin'
	compiler='/usr/local/Cellar/gcc/10.2.0/bin/g++-10'
elif [[ "$OSTYPE" == "cygwin" ]]; then
    echo 'cygwin'
	# POSIX compatibility layer and Linux environment emulation for Windows
elif [[ "$OSTYPE" == "msys" ]]; then
    echo 'msys'
	# Lightweight shell and GNU utilities compiled for Windows (part of MinGW)
elif [[ "$OSTYPE" == "win32" ]]; then
    echo 'win32'
	# I'm not sure this can happen.
elif [[ "$OSTYPE" == "freebsd"* ]]; then
    echo 'freebsd'
else
	echo 'unknown'
fi

$compiler -Wall -Wextra -Wshadow -std=c++14 -fanalyzer $PROBLEM.cpp
