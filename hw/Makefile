# Makefile to ease trivial tasks for the project

all: convert

.PHONY: convert convert1 convert2
convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	pdflatex -output-directory=$(dir ${DOC}) ${DOC}

.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name '*.log' -o -name '*.aux' \) -delete
