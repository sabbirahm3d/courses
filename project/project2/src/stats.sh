#!/usr/bin/env zsh
set -o errexit

cores=( 1 2 4 )

for core in "${cores[@]}"
do
    echo $core;
    for (( i = 1; i <= 5; i++))
    do

        make -s run SEQ1LEN=10000 SEQ2LEN=10000 THREADS=$core;

    done
done
