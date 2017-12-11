# Makefile to ease trivial tasks for the project

all: convert


.PHONY: convert convert1 convert2
convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex ${DOC}.tex


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
