MAIN:="main"
DEP:="music"

.PHONY: run
run:
	@./${MAIN}.o


.PHONY: compile
compile:
	@gcc -o ${MAIN}.o ${MAIN}.c ${DEP}.c -Wall -std=gnu99 -Os


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
