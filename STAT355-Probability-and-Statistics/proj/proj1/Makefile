# Makefile to ease trivial tasks for the project
DOCFILE="$(shell find -name "*.tex")"

all: compute convert

.PHONY: compute
compute:
	# compile the R script
	@Rscript main.R

.PHONY: convert
convert:
	# convert LaTex file to PDF
	@sudo pdflatex $(DOCFILE)
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
