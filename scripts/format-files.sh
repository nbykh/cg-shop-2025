#!/bin/bash

find ./test -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i
find ./scripts -iname '*.py' | xargs autopep8 -i