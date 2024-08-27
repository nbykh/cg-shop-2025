#!/bin/bash

exit_code=0
find ./test -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format --dry-run --Werror -i
if [[ $? -ne 0 ]]; then
    exit_code=1
fi

black --check scripts/*.py
if [[ $? -ne 0 ]]; then
    exit_code=1
fi

if [[ $exit_code -ne 0 ]]; then
    echo "[FAILED] Please fix format: run "
    echo "  bash ./scripts/format-files.sh"
    exit $exit_code
fi
