MAIN:="main"
DEP:="database"

.PHONY: run
run:
	@./${MAIN}.o ${INPUT}


.PHONY: build
build:
	@gcc -o ${MAIN}.o ${MAIN}.c ${DEP}.c -Wall -std=gnu99 -Os


.PHONY: val
val:
	@valgrind --leak-check=full --track-origins=yes -v ./${MAIN}.o ${INPUT}

.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
