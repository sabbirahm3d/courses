#!/bin/bash
#SBATCH --job-name=lcs_length
#SBATCH --output lcs_length16.out
#SBATCH --error lcs_length16.err
#SBATCH --partition=batch
#SBATCH --qos=short
#SBATCH --constraint=hpcf2013
#SBATCH --exclusive
#SBATCH --cpus-per-task=16
#SBATCH --ntasks=1

export KMP_AFFINITY="verbose,compact"
export OMP_NUM_THREADS=8
srun ./stats.sh
