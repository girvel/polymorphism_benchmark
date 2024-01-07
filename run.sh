#!/usr/bin/env bash

mkdir -p build
g++-13 -std=c++20 main.cpp -o build/main && time ./build/main "$@"
