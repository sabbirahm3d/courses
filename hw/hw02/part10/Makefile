# Makefile to ease trivial tasks for the project


.PHONY: compile
compile:
	# compile and dump test bench 
	@iverilog -o scripts/dump.o scripts/part10_linear_shift_reg.v \
		scripts/part10_linear_shift_reg_tb.v
	@./scripts/dump.o > scripts/linear_shift_reg_dump.txt


.PHONY: test
test:
	# run the Python script to verify the test bench simulation generated the
	# expected terms for the LFSR
	@python scripts/linearshiftpat.py


.PHONY: clean
clean:
	# look for the test bench executable, and delete if it exists
	@find . -name dump.o -type f -delete
	@find . -regex '.*\.\(aux\|log\)' -delete


.PHONY: convert convert1 convert2
convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex report.tex
