MAIN:="main"

.PHONY: run
run:
	# run the executable with a command line argument
	@./${OUTPUT} ${PATH}


.PHONY: compile
compile:
	# build the main script
	@g++ -o ${MAIN}.o ${MAIN}.cpp ${MAIN}.h -lgmpxx -lgmp -std=c++0x -Wall


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
