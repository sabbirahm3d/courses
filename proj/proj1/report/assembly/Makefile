# Makefile to ease trivial tasks for the project

.PHONY: run
run:
	# compile and run script
	@nasm -f elf $(SCRIPT).asm
	@ld -s -o $(SCRIPT).out $(SCRIPT).o -lc
	@./$(SCRIPT).out


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(out\|o\)' -delete
