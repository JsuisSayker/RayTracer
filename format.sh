#!/bin/bash

grep_str="^.*.[cpp|hpp]$"

clang-format -i $(find $(pwd)/plugins -maxdepth 5 -type f -not -path '*/\.*' | grep $grep_str)
clang-format -i $(find $(pwd)/src -maxdepth 5 -type f -not -path '*/\.*' | grep $grep_str)
clang-format -i $(find $(pwd)/app -maxdepth 5 -type f -not -path '*/\.*' | grep $grep_str)
clang-format -i $(find $(pwd)/interface -maxdepth 5 -type f -not -path '*/\.*' | grep $grep_str)