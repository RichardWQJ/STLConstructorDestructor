#!/bin/bash
if [ ! -n $1 ]; then
	echo "Input: build.sh <filename>"
	exit
fi

g++ $1 -std=c++11 -o TEST
