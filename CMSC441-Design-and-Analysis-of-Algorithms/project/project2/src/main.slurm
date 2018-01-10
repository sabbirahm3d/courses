#!/bin/bash
#SBATCH --job-name=lcs_length
#SBATCH --output slurm.out
#SBATCH --error slurm.err
#SBATCH --partition=batch
#SBATCH --qos=medium
#SBATCH --constraint=hpcf2013
#SBATCH --exclusive
#SBATCH --cpus-per-task=16
#SBATCH --ntasks=1
#SBATCH --mem=50000

export KMP_AFFINITY="verbose,compact"
export OMP_NUM_THREADS=8
srun ./stats.sh
