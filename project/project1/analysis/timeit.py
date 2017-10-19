#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""Analyzes the outputs generated by the driver script. Simple statistics, such
as the means, medians and standard deviations are computed for each sample
input files. The differences between the two multiplication methods are also
computed.

The script is meant to be executed in conjunction with the Makefile:

    make timeit --no-print-directory -s
"""


from itertools import zip_longest
from statistics import mean, median, stdev

if __name__ == "__main__":

    cmul4_times = []
    cmul3_times = []
    complex_nums = ""

    # open execution times dumped in the loops
    with open("analysis/times.txt") as times_file:
        complex_nums = next(times_file).split('/')[-1][:-1]  # file name
        # efficient method of reading 4 lines of the file per iteration
        for _, cmul4, _, cmul3 in zip_longest(*[times_file] * 4):
            cmul4_times.append(float(cmul4[6:-1]))  # times for cmul4
            cmul3_times.append(float(cmul3[6:-1]))  # times for cmul3

    len_cmul = float(len(cmul4_times))  # length of cmul4 times == cmul3 times
    # compute the difference of the times per each execution
    diffs = [float("{0:.6f}".format((x - y) * 1000))
             for x, y in zip(cmul4_times, cmul3_times)]

    # open file to dump the analysis
    with open("analysis/timestats/" + complex_nums, 'w') as output_file:

        # means
        print("cmul4 ave: {0:.6f} ms".format(
            mean(cmul4_times) * 1000), file=output_file)
        print("cmul3 ave: {0:.6f} ms".format(
            mean(cmul3_times) * 1000), file=output_file)

        # medians
        print("cmul4 med: {0:.6f} ms".format(
            median(cmul4_times) * 1000), file=output_file)
        print("cmul3 med: {0:.6f} ms".format(
            median(cmul3_times) * 1000), file=output_file)

        # standard deviations
        print("cmul4 std: {0:.6f} ms".format(
            stdev(cmul4_times) * 1000), file=output_file)
        print("cmul3 std: {0:.6f} ms".format(
            stdev(cmul3_times) * 1000), file=output_file)

        # differences in the execution times
        print("diffs:", file=output_file)
        print(diffs, file=output_file)
        # mean of differences
        print("diffs mean: {0:.6f} ms".format(mean(diffs)), file=output_file)
