# Makefile to ease trivial tasks for the project
DOCFILE="$(shell find -name "*.tex")"

.PHONY: convert
convert:
	# convert LaTex to PDF
	@sudo pdflatex $(DOCFILE)
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\|pdf\)' -delete
