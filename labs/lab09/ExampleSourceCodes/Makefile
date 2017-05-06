
.PHONY: run
run:
	# compile and run script
	@nasm -f elf64 $(SCRIPT).asm
	@ld -s -o $(SCRIPT).out $(SCRIPT).o
	@./$(SCRIPT).out

.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\|out\|o\)' -delete
