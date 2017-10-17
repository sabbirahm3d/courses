# Makefile to ease usage and building of the program

# the number of iterations desired are saved to a file for compatibility issues
# between zsh and bash scripts
LOOPS:=$(shell cat analysis/loop.txt)
TIMES:="analysis/times.txt"
INPUTS:=$(shell ls sample_input/)

default: run

.PHONY: run
run:
	# run the executable with a command line argument
	@./main.o ${PATH}


.PHONY: compile
compile:
	# build the main script
	@g++ -o main.o main.cpp gmpxx.h -lgmp -std=c++0x -Wall


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -o -name "*.pyc" -type f -delete


.PHONY: clean-compile
clean-compile:
	# clean then compile executable
	@make -s clean && make -s compile


.PHONY: timeit
timeit:
	# clean compile and run 
	@for file in ${INPUTS}; do \
		truncate -s 0 ${TIMES}; \
		echo $${file} > ${TIMES}; \
		for i in ${LOOPS}; do \
			make clean-compile; \
			make run PATH=sample_input/$${file} >> ${TIMES}; \
		done; \
		python3 analyis/timeit.py; \
	done
