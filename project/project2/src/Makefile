# main Makefile for Project 2

SIZE = 10000
SEQ1 = seq1.txt
SEQ2 = seq2.txt
SEQ1LEN = 10000
SEQ2LEN = 10000
SUBMITFILE = jobid.txt

# define the C compiler to use
CC := gcc

# define any compile-time flags
CFLAGS := -std=c99 -Wall -fopenmp -lm

# define the C source files
SRC = lcs_length.c

# define the executable file
EXE = lcs_length

yo:
	$(CC) lol.c -fopenmp -ansi -Wall -std=c99 -lm -g -o lcs-omp

# ---------- executing targets ----------

.PHONY: run
run:
	# run executable
	./${EXE} ${SEQ1} ${SEQ1LEN} ${SEQ2} ${SEQ2LEN}


# ---------- memory checking targets ----------

.PHONY: val
val:
	# check memory leaks
	valgrind --leak-check=full --show-leak-kinds=all ./${EXE} ${SEQ1} ${SEQ1LEN} ${SEQ2} ${SEQ2LEN}


# ---------- building targets ----------

.PHONY: build
build:
	${CC} ${SRC} ${CFLAGS} -o ${EXE}


# ---------- generating random sequences targets ----------

.PHONY: genrand
genrand:
	# generate random sequence of ACTG of size {SIZE}
	cat /dev/urandom | tr -dc 'ACTG' | fold -w ${SIZE} | head -n 1 | \
		tr -d '\n'

.PHONY: genseqs
genseqs:
	# generate 2 random sequence files
	${MAKE} -s genrand > ${SEQ1}
	${MAKE} -s genrand > ${SEQ2}


# ---------- SLURM batch targets ----------

.PHONY: slurmsubmit
slurmsubmit:
	sbatch ${EXE} slurm > ${SUBMITFILE}

.PHONY: slurmstat
slurmstat:
	sstat ${JOBID}

.PHONY: slurmqueue
slurmqueue:
	squeue | grep ${USER}

# ---------- cleaning targets ----------

.PHONY: clean
clean:
	# clean out binary files
	find . \( -name "*.o" -o -name ${EXE} \) -type f -delete

.PHONY: reset
reset:
	# reset data files
	${MAKE} --no-print-directory clean
	@if [ -f ${SEQ1} ]; then >${SEQ1};\
	else touch ${SEQ1}; \
	fi
	@if [ -f ${SEQ2} ]; then >${SEQ2};\
	else touch ${SEQ2}; \
	fi
