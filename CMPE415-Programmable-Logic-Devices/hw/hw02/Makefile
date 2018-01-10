# Makefile to ease trivial tasks for the project


makefiles=$(shell find . -maxdepth 1 -path "./part*" -type d -print | sort)


.PHONY: convert-all
convert-all:
	# call make convert to generate all reports
	@for mk in ${makefiles}; do \
		cd $${mk}; \
		make convert; \
		cd ..; \
	done


.PHONY: clean-all
clean-all:
	# call make clean to clean all cache
	@for mk in ${makefiles}; do \
		cd $${mk}; \
		make clean; \
		cd ..; \
	done
