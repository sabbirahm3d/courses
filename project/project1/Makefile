# Makefile to ease usage and testing of the program

# the number of iterations desired are saved to a file for compatibility issues
# with zsh and bash scripts
LOOPS:=$(shell cat loop.txt)
TIMES:="times.txt"


.PHONY: run
run:
	# run the executable with a command line argument
	@./main.o ${PATH}


.PHONY: compile
compile:
	# build the main script
	@g++ -o main.o main.cpp gmpxx.h -lgmp -std=c++0x -Wall


.PHONY: time
time:
	# call make convert to generate all reports
	@truncate -s 0 ${TIMES}
	@echo ${FILE} > ${TIMES}
	@for i in ${LOOPS}; do \
		make compile; \
		make run PATH=${FILE} >> ${TIMES}; \
		make clean; \
	done
	@python time.py


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
