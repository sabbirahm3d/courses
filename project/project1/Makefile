OUTPUT:="main.o"
MAIN:="add_example"

.PHONY: run
run:
	@./${OUTPUT}


.PHONY: install
install:
	@g++ -o ${OUTPUT} ${MAIN}.cpp -lgmp


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
