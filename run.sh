#!/usr/bin/env bash

mkdir -p build
echo -e "\n----- POLYMORPHISM -----"
g++-13 -std=c++20 polymorphism.cpp -o build/main && ./build/main "$@"

echo -e "\n----- FUNCTION POINTERS -----"
g++-13 -std=c++20 function_pointers.cpp -o build/main && ./build/main "$@"
