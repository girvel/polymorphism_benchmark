#!/usr/bin/env bash

mkdir -p build
g++-13 -std=c++20 "$1" -o build/main && ./build/main "$2"
