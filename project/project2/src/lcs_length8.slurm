#!/bin/bash
#SBATCH --job-name=lcs_length
#SBATCH --output lcs_length8.out
#SBATCH --error lcs_length8.err
#SBATCH --partition=batch
#SBATCH --qos=short
#SBATCH --constraint=hpcf2010
#SBATCH --exclusive
#SBATCH --cpus-per-task=8
#SBATCH --ntasks=1

export KMP_AFFINITY="verbose,compact"
export OMP_NUM_THREADS=8
srun ./stats.sh
