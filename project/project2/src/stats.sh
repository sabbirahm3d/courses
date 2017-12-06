#!/usr/bin/env bash
set -o errexit

cores=( 1 2 4 8 16 )
seqlens=( 500 1000 2500 5000 10000 25000 )

for (( i = 0; i < ${#cores[@]}; i++))
do
    for (( j = 0; j < ${#seqlens[@]}; j++))
    do

        for (( k = 0; k <= j; k++))
        do

            echo "CORES: ${cores[i]} LEN1: ${seqlens[k]} LEN2: ${seqlens[j]}";
            for (( l = 1; l <= 5; l++))
            do
                make -s run SEQ1LEN=${seqlens[k]} SEQ2LEN=${seqlens[j]} THREADS=${cores[i]};
            done

        done

    done

done
