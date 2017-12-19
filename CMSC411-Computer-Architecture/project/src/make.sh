#!/usr/bin/env bash
# CMSC 411, Fall 2017, Term project execution script

python2 simulator.py $(find . -name "inst*.txt") $(find . -name "data*.txt") output.txt
