# Makefile to ease trivial tasks for the project


makefiles=$(shell find . -path "./part*/Makefile" -type f -print)


.PHONY: clean-all
clean-all:
	# convert LaTex file to PDF
	@for mk in ${makefiles}; do \
		make -f $$mk clean; \
	done


.PHONY: clean-all
clean-all:
	# convert LaTex file to PDF
	@for mk in ${makefiles}; do \
		make -f $$mk clean; \
	done
