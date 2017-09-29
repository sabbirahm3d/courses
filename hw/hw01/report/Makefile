# Makefile to ease trivial tasks for the project

all: convert preview

.PHONY: convert convert1 convert2
convert: convert1 convert2  # file is compiled twice to pick up cached info
convert1 convert2:
	# convert LaTex file to PDF
	@pdflatex ${DOC}.tex


.PHONY: preview
preview:
	# preview PDF version of the file
	@evince ${DOC}.pdf & disown


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name "*.log" -o -name "*.aux" \) -type f -delete
