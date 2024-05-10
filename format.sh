#!/bin/bash

grep_str="^.*.[cpp|hpp]$"

plugins_app="$(find "$(pwd)/plugins" -maxdepth 5 -type f -not -path '*/\.*' | grep "$grep_str")"
clang-format -i $plugins_app
src_app="$(find "$(pwd)/src" -maxdepth 5 -type f -not -path '*/\.*' | grep "$grep_str")"
clang-format -i $src_app
app_files="$(find "$(pwd)/app" -maxdepth 5 -type f -not -path '*/\.*' | grep "$grep_str")"
clang-format -i $app_files
interface_files="$(find "$(pwd)/interface" -maxdepth 5 -type f -not -path '*/\.*' | grep "$grep_str")"
clang-format -i $interface_files