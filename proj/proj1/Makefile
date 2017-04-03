# Makefile to ease trivial tasks for the project

.PHONY: convert
convert:
	# convert LaTex file to PDF
	@sudo pdflatex report.tex
	@sudo chown -R $(USER) .


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . -regex '.*\.\(aux\|log\)' -delete
