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
	@g++ -o main.o main.cpp -lgmp -lgmpxx -std=c++0x -Wall


.PHONY: clean
clean:
	# clean compiled executables
	@find . -name "*.o" -type f -delete


.PHONY: clean-all
clean-all:
	# clean out cache and temporary files
	@make --no-print-directory clean
	# clean temporary LaTex files
	@find . \( -name "*.log" -o -name "*.aux" \) -type f -delete
	# clean compiled Python files
	@find . \( -name "__pycache__" -type d -o -name "*.pyc" -type f \) -delete


.PHONY: clean-compile
clean-compile:
	# clean then compile executable
	@make clean && make compile


.PHONY: timeit
timeit:
	# clean compile and run 
	@for file in ${INPUTS}; do \
		echo "Timing with $${file}"; \
		truncate -s 0 ${TIMES}; \
		echo $${file} > ${TIMES}; \
		for i in ${LOOPS}; do \
			make -s clean-compile; \
			make -s run PATH=sample_input/$${file} >> ${TIMES}; \
		done; \
		python3 analysis/timeit.py; \
	done
