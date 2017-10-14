MAIN:="main"
LOOPS:=$(shell cat loop.txt)
TIMES:="times.txt"

.PHONY: run
run:
	# run the executable with a command line argument
	@./${MAIN}.o ${PATH}


.PHONY: compile
compile:
	# build the main script
	@g++ -o ${MAIN}.o ${MAIN}.cpp ${MAIN}.h gmpxx.h -lgmp -std=c++0x -Wall


.PHONY: time
time:
	# call make convert to generate all reports
	@truncate -s 0 ${TIMES}
	@echo ${FILE} > ${TIMES}
	@for i in ${LOOPS}; do \
		make run PATH=${FILE} >> ${TIMES}; \
	done


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
