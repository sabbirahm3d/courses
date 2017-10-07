# Makefile to ease trivial tasks for the project


makefiles=$(shell find . -path "./part*" -type d ! -path "./part*/figures" \
	! -path "./part*/scripts" -print | sort)


.PHONY: convert-all
convert-all:
	# call make convert to generate all reports
	@for mk in ${makefiles}; do \
		cd $$mk; \
		make convert; \
	done


.PHONY: clean-all
clean-all:
	# call make clean to clean all cache
	@for mk in ${makefiles}; do \
		cd $$mk; \
		make clean; \
	done
