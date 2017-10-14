#!/usr/bin/env python
# -*- coding: utf-8 -*-

# make time FILE=${FILE} --no-print-directory -s

import itertools

if __name__ == '__main__':

    cmul4_times = []
    cmul3_times = []
    complex_nums = ""

    with open('times.txt') as times_file:
        complex_nums = next(times_file)
        for _, cmul4, _, cmul3 in itertools.izip_longest(*[times_file] * 4):
            cmul4_times.append(float(cmul4[6:-1]))
            cmul3_times.append(float(cmul3[6:-1]))

    len_cmul = float(len(cmul4_times))

    print "file:", complex_nums,
    print "cmul4 ave:", sum(cmul4_times) / len_cmul
    print "cmul3 ave:", sum(cmul3_times) / len_cmul
