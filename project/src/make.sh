#!/usr/bin/env bash

python2 simulator.py $(find . -name "inst*.txt") $(find . -name "data*.txt") output.txt
