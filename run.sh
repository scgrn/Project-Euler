#!/bin/bash

g++ p$1/p$1.cpp -o test
if [ $? -eq 0 ]
then
  time ./test
  rm ./test
fi

