#!/bin/sh
rm ./demo.out
command="g++ main.cpp `pkg-config --cflags --libs opencv` -std=c++11 -o demo.out"
result=`$command`
if [ ! -f "demo.out" ];
then 
    echo "compile error"
else   
    echo "build succeed"
    ./demo.out
fi