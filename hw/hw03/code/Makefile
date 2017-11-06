MAIN:="main"
DEP:="database"

.PHONY: run
run:
	@./${MAIN}.o ${INPUT}


.PHONY: compile
compile:
	@gcc -o ${MAIN}.o ${MAIN}.c ${DEP}.c -Wall -std=gnu99 -Os


.PHONY: memleak
memleak:
	@valgrind -v --leak-check=full --track-origins=yes ./${MAIN}.o ${INPUT}

.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
