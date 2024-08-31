#!/bin/bash

# format C++ files
find ./test -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
find ./src -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
# format Python files
black scripts/*.py