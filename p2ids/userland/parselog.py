#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from parsesyscalls import get_sys_call_names
from pprint import pprint

BASE_PATH = path.abspath(__file__)


def parse_log(log_path):

    sys_calls = []
    get_sys_call_names()
    window = []

    with open(log_path) as log_file:
        for line in log_file:
            split_line = line.split()

            if not any(split_line[0] in sublist for sublist in window):
                sys_calls.append(window)
                window = []
            window.append(split_line)

    sys_calls.append(window)

    return filter(None, sys_calls)


def chunk_window(seq, k):

    seq_len = len(seq)

    if (k < seq_len):
        chunked = []
        for elem in xrange(seq_len - k + 1):
            chunked.append(seq[elem:elem + k])

        return chunked

    return [seq]


def vectorize(seq, healthy_seq=None):

    vectorized_seq = {}
    vectorized_seq["seqs"] = seq
    if (not healthy_seq):

        vectorized_seq["healthy"] = True

    else:

        hamming_dist = 0
        for window, healthy_window in zip(seq, healthy_seq["seqs"]):
            for sys_call, healthy_sys_call in zip(window, healthy_window):
                if sys_call[1] != healthy_sys_call[1]:
                    hamming_dist += 1
        vectorized_seq["hamming_dist"] = hamming_dist

    return vectorized_seq


def analyze_prog(log_file, k):

    log = parse_log(log_file)
    healthy = 0
    prog_db = []
    for sys_calls in log:
        windows = chunk_window(sys_calls, k)
        if (not healthy):
            vec = vectorize(windows, healthy_seq=None)
            prog_db.append(vec)
            healthy = 1
        else:
            vec = vectorize(windows, healthy_seq=prog_db[0])
            prog_db.append(vec)

    return prog_db


if __name__ == '__main__':

    pprint(analyze_prog("sample.log", k=3))
