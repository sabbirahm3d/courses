# Makefile to ease trivial tasks for the project


.PHONY: convert convert1 convert2
convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex report.tex


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name "*.log" -o -name "*.aux" \) -type f -delete
