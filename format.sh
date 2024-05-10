#!/bin/bash

clang-format -i $(find $(pwd)/plugins -maxdepth 5 -type f -not -path '*/\.*' | grep ".[c|h][p][p]$")
clang-format -i $(find $(pwd)/src -maxdepth 5 -type f -not -path '*/\.*' | grep ".[c|h][p][p]$")
clang-format -i $(find $(pwd)/app -maxdepth 5 -type f -not -path '*/\.*' | grep ".[c|h][p][p]$")
clang-format -i $(find $(pwd)/interface -maxdepth 5 -type f -not -path '*/\.*' | grep ".[c|h][p][p]$")