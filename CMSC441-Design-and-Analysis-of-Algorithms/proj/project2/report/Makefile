# Makefile for compiling LaTex files

default: convert

.PHONY: convert convert1 convert2
convert: convert1 convert2  # file is compiled twice to pick up cached info
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex ${DOC}
	@bibtex *.aux


.PHONY: clean
clean:
	# clean out temporary files
	find . \( -name "*.aux" -o -name "*.log" -o -name "*.blg" \
		-o -name "*.bbl" \) -type f -delete
