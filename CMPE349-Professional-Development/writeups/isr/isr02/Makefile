# Makefile to ease trivial tasks for the project
DOCFILE="$(shell find -name "*.tex")"

.PHONY: cache_convert convert1 convert2
cache_convert: convert1 convert2
convert1 convert2:
	# convert LaTex file to PDF
	@sudo pdflatex $(DOCFILE)
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
