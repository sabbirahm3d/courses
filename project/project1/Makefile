OUTPUT:="main.o"
MAIN:="main"

.PHONY: run
run:
	@./${OUTPUT}


.PHONY: compile
compile:
	@g++ -o ${OUTPUT} ${MAIN}.cpp -lgmp


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
