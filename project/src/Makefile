# Makefile to ease trivial tasks for the project

INST?=$(shell find . -name "inst*.txt")
DATA?=$(shell find . -name "data*.txt")
OUT?="output.txt"

all: run

.PHONY: run
run: clean
	# execute the main script
	python simulator.py ${INST} ${DATA} ${OUT}
	cat ${OUT}


.PHONY: clean
clean:
	# clean out temporary and cached files
	find . -name "*.pyc" -type f -delete
	if [ -f ${OUT} ]; then >${OUT};\
	else touch ${OUT}; \
	fi
