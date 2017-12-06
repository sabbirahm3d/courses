#!/usr/bin/env zsh
set -o errexit

cores=( 1 2 4 8 16 )
seq1=( 500 1000 2500 5000 10000 25000 )
seq2=( 500 1000 2500 5000 10000 25000 )

for (( i = 1; i <= ${#cores[@]}; i++))
do
    for (( j = 1; j <= ${#seq1[@]}; j++))
    do

        for (( k = 1; k <= j; k++))
        do

            echo "CORES:\t$cores[i]\tLEN1:\t$seq1[k]\tLEN2:\t$seq2[j]";
            for (( l = 1; l <= 5; l++))
            do
                make -s run SEQ1=$seq1[k] SEQ2=$seq2[j] THREADS=$cores[i];
            done

        done

    done

done
