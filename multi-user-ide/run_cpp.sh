#!/bin/bash

infile=$1

if [ $# -lt 1 ]; then
	echo "Error! not enough arguments"
	exit
fi

g++ -std=c++11 "run/$infile" -o "run/$infile.bin" > "run/$infile.txt" 2>&1 

if [ $? = 0 ]; then
	cd run
	timeout 3 "./$infile.bin" > "$infile.txt"
	echo -ne "\nProgram returned $?" >> "$infile.txt"
	cd ..
fi

cat "run/$infile.txt"
cd ..