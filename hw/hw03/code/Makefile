MAIN:="main"
DEP:="list"

.PHONY: run
run:
	@./${MAIN}.o


.PHONY: compile
compile:
	@gcc -o ${MAIN}.o ${MAIN}.c ${DEP}.c -Wall -std=gnu99 -Os


.PHONY: memleak
memleak:
	@valgrind -v --leak-check=full ./${MAIN}.o

.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
