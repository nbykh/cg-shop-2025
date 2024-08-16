#!/bin/bash

find ./test -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i