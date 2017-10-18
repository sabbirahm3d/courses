# Makefile to ease trivial tasks for the project

.PHONY: convert convert1 convert2
convert: convert1 convert2  # file is compiled twice to pick up cached info
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex report.tex
