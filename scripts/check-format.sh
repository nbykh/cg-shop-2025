#!/bin/bash

find ./test -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format --dry-run --Werror -i
if [[ $? -ne 0 ]]; then
    echo "[FAILED] Please fix format: run "
    echo "  bash ./scripts/format-files.sh"
    exit 1
fi
