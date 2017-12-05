#!/usr/bin/env zsh
set -o errexit

for (( i = 1; i <= 5; i++)) do

    make run SEQ1LEN=10000 SEQ2LEN=10000 THREADS=4

done
