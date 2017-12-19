#!/usr/bin/env bash
# Helper script to automate generation of execution times of lcs_length on 1,
# 2, 4, 8, and 16 cores. This script is intended to be used with Slurm, but may
# be executed independently as long-running job.

set -o errexit

cores=( 1 2 4 8 16 )
seqlens=( 500 1000 2500 5000 10000 25000 50000 100000 )

for (( i = 0; i < ${#cores[@]}; i++))
do
    for (( j = 0; j < ${#seqlens[@]}; j++))
    do

        for (( k = 0; k <= j; k++))
        do

            echo "CORES: ${cores[i]} LEN1: ${seqlens[k]} LEN2: ${seqlens[j]}";
            for (( l = 0; l < 5; l++))
            do
                make -s run SEQ1LEN=${seqlens[k]} SEQ2LEN=${seqlens[j]} THREADS=${cores[i]};
            done

        done

    done

done
