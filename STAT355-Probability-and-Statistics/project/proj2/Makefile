# Makefile to ease trivial tasks for the project

all: compute cache_convert changeown


.PHONY: compute
compute:
	# compile the R script
	@Rscript main.R


.PHONY: cache_convert convert1 convert2
cache_convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@sudo pdflatex report.tex


.PHONY: changeown
changeown:
	# change file permissions
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
