# Makefile to ease trivial tasks for the project

all: cache_convert changeown


.PHONY: cache_convert convert1 convert2
cache_convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@sudo pdflatex intro.tex


.PHONY: changeown
changeown:
	# change file permissions
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
