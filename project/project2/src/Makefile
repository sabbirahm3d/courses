SIZE = 10000
SEQ1 = seq1.txt
SEQ2 = seq2.txt


# define the C compiler to use
CC := g++

# define any compile-time flags
CPPFLAGS := -std=c++0x -Wall

# define the C++ source files
SRCS = main.cpp

# define the C++ object files 
OBJS := ${SRCS:.cpp=.o}

# define the executable file 
EXE = main

# ---------- executing targets ----------

.PHONY: run
run:
	# run executable
	./${EXE} ${SEQ1} ${SEQ2}


# ---------- memory checking targets ----------

.PHONY: val
val:
	# check memory leaks
	valgrind --leak-check=full -v --show-leak-kinds=all ./${EXE} ${SEQ1} ${SEQ2}


# ---------- building targets ----------

${EXE}: ${OBJS} 
	${CC} ${CPPFLAGS} -o ${EXE} ${OBJS}

.cpp .o:
	${CC} ${CPPFLAGS} -c $< -o $@

.PHONY: build
build: ${EXE}
	@echo "Program compiled successfully"


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


# ---------- cleaning targets ----------

.PHONY: clean
clean:
	# clean out binary files
	find . \( -name "*.o" -o -name "main" \) -type f -delete

.PHONY: reset
reset:
	# reset data files
	${MAKE} --no-print-directory clean
	if [ -f ${SEQ1} ]; then >${SEQ1};\
	else touch ${SEQ1}; \
	fi
	if [ -f ${SEQ2} ]; then >${SEQ2};\
	else touch ${SEQ2}; \
	fi
