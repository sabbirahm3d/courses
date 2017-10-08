OUTPUT:="main.o"
MAIN:="main"

.PHONY: run
run:
	@./${OUTPUT} ${PATH}


.PHONY: compile
compile:
	@g++ -o ${OUTPUT} ${MAIN}.cpp ${MAIN}.h -lgmpxx -lgmp -std=c++0x


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
