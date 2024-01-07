#!/usr/bin/env bash

mkdir -p build
echo -e "\n----- VIRTUAL METHODS -----"
g++-13 -std=c++20 virtual_methods.cpp -o build/main && ./build/main "$@"

echo -e "\n----- FUNCTION POINTERS -----"
g++-13 -std=c++20 function_pointers.cpp -o build/main && ./build/main "$@"

echo -e "\n----- FUNCTION POINTERS IN OBJECTS -----"
g++-13 -std=c++20 function_pointers_in_objects.cpp -o build/main && ./build/main "$@"
