#!/usr/bin/env bash

python2 main.py $(find . -name "inst*.txt") $(find . -name "data*.txt") output.txt
