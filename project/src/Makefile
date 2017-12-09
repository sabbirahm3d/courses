# CMSC 411, Fall 2017, Term project Makefile

INST?=$(shell find . -name "inst*.txt")
DATA?=$(shell find . -name "data*.txt")
OUT?="output.txt"

all: debug

.PHONY: debug
debug: clean
	# execute the main script
	@python simulator.py ${INST} ${DATA} ${OUT}
	@echo "\n"
	@diff -y --width=170 ${OUT} actual.txt


.PHONY: clean
clean:
	# clean out temporary and cached files
	@find . -name "*.pyc" -type f -delete
	@if [ -f ${OUT} ]; then >${OUT};\
	else touch ${OUT}; \
	fi
