SIZE = 10000
SEQ1 = seq1.txt
SEQ2 = seq2.txt


# define the C compiler to use
CC := g++

# define any compile-time flags
CPPFLAGS := -std=c++0x -Wall

# define the C source files
SRCS = main.cpp

# define the C object files 
OBJS := ${SRCS:.c=.o}

# define the executable file 
EXE = main.o


.PHONY: run
run:
	@./${EXE} ${SEQ1} ${SEQ2}


.PHONY: build
build: ${EXE}
	@echo "Program compiled successfully"


${EXE}: ${OBJS} 
	${CC} ${CPPFLAGS} -o ${EXE} ${OBJS}

.c.o:
	${CC} ${CPPFLAGS} -c $< -o $@


.PHONY: genrand
genrand:
	@cat /dev/urandom | tr -dc 'ACTG' | fold -w ${SIZE} | head -n 1 | \
		tr -d '\n'


.PHONY: genseqs
genseqs:
	@${MAKE} genrand -s > ${SEQ1}
	@${MAKE} genrand -s > ${SEQ2}


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name "*.o" -o -name ${EXE} \) -type f -delete


.PHONY: reset
reset:
	# reset data files
	@${MAKE} --no-print-directory clean
	@if [ -f ${SEQ1} ]; then \
		>${SEQ1};\
	else \
		touch ${SEQ1}; \
	fi
	@if [ -f ${SEQ2} ]; then \
		>${SEQ2};\
	else \
		touch ${SEQ2}; \
	fi
