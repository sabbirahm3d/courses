
.PHONY: genrand
genrand:
	@cat /dev/urandom | tr -dc 'ACTG' | fold -w 10000 | head -n 1 | tr -d '\n'

.PHONY: genseqs
genseqs:
	@${MAKE} genrand -s > seq1.txt
	@${MAKE} genrand -s > seq2.txt
