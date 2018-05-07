#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from parsesyscalls import get_sys_call_names
from util import read_data, write_data
from pprint import pprint

BASE_PATH = path.abspath(__file__)
try:
    range = xrange
except NameError:
    pass


class IntrusionDetectionSystem(object):

    def __init__(self, prog_name, window_size, custom=None):

        self.prog_name = prog_name
        self.healthy_seq_name = self.prog_name[:-4] + \
            "_healthy.json" if not custom else custom
        self.healthy_seq = []
        self.window_size = window_size

    def set_healthy_seq(self):

        seqs = self.parse_log(self.prog_name)

        chunked_sequence = []
        for seq in seqs:
            chunked_sequence.extend(self.chunk_window(seq, self.window_size))

        return write_data(self.healthy_seq_name, chunked_sequence)

    def get_healthy_seq(self):

        return read_data(self.healthy_seq_name)

    def parse_log(self, log_path):

        sys_calls = []
        sys_call_names = get_sys_call_names()
        window = []

        with open(log_path) as log_file:

            for line in log_file:
                split_line = line.split()
                split_line += [sys_call_names[split_line[1]]]

                if not any(split_line[0] in sublist for sublist in window):
                    sys_calls.append(window)
                    window = []

                window.append(split_line)

            sys_calls.append(window)

        return filter(None, sys_calls)

    def chunk_window(self, seq, k):

        seq_len = len(seq)

        if (k < seq_len):
            chunked = []
            for elem in range(seq_len - k + 1):
                chunked.append(seq[elem:elem + k])

            return chunked

        return [seq]

    def vectorize(self, seq):

        vectorized_seq = {}
        vectorized_seq["seqs"] = seq

        healthy_seq = self.get_healthy_seq()
        hamming_dist = 0
        for window, healthy_window in zip(seq, healthy_seq):
            for sys_call, healthy_sys_call in zip(window, healthy_window):
                if sys_call[1] != healthy_sys_call[1]:
                    hamming_dist += 1
        vectorized_seq["hamming_dist"] = hamming_dist

        return vectorized_seq

    def analyze_prog(self):

        prog_log = self.parse_log(self.prog_name)
        prog_db = []
        for sys_calls in prog_log:
            windows = self.chunk_window(sys_calls, self.window_size)
            vec = self.vectorize(windows)
            prog_db.append(vec)

        return prog_db


if __name__ == '__main__':

    ids_obj1 = IntrusionDetectionSystem("sample.log", window_size=3)
    ids_obj1.set_healthy_seq()
    ids_obj2 = IntrusionDetectionSystem(
        "sample1.log", window_size=3, custom="sample_healthy.json")
    pprint(ids_obj2.analyze_prog())
