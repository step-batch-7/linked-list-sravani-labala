#! /bin/bash
path=$1
excecutable=$2
mkdir -p bin
rm -rf *.o
gcc -c $path*.c
gcc -o ./bin/$excecutable *.o && ./bin/$excecutable
rm -rf *.o
rm -rf ./bin