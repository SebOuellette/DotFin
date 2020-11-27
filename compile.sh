#!/bin/bash

# Compile everything in one command
g++ -pthread -v -std=c++17 -o dotfin src/functions/*.cpp src/classes/*.cpp src/lexer/*.cpp src/math/*.cpp main.cpp

# Split the verbose output of the compiler, and the output of the program
echo -e "\n\n\n\n\n"

# Run our example
./dotfin ./examples/lang.fin