MAIN:="music"

.PHONY: run
run:
	@./${MAIN}.o ${PATH}


.PHONY: compile
compile:
	@gcc -o ${MAIN}.o ${MAIN}.c ${MAIN}.h -Wall


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -name "*.o" -type f -delete
