#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from parsesyscalls import get_sys_call_names
from util import read_data, write_data

BASE_PATH = path.abspath(__file__)
try:
    range = xrange
except NameError:
    pass


class LogParser(object):

    def __init__(self, prog_name):

        self.prog_name = prog_name
        self.healthy_seq_name = prog_name[:-10] + "_healthy.json"

    def set_healthy_seq(self, window_size):

        seqs = self.parse_log(self.prog_name)

        chunked_sequence = []
        for seq in seqs:
            chunked_sequence.extend(self.chunk_window(seq, window_size))

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

    def get_hamming_dist(self, seq, healthy_seq):

        vectorized_seq = {}
        vectorized_seq["seqs"] = seq

        hamming_dist = 0
        for window, healthy_window in zip(seq, healthy_seq):
            for sys_call, healthy_sys_call in zip(window, healthy_window):
                if sys_call[1] != healthy_sys_call[1]:
                    hamming_dist += 1
        vectorized_seq["hamming_dist"] = hamming_dist

        return vectorized_seq

    def vectorize(self, prog_name, window_size):

        prog_log = self.parse_log(prog_name)
        prog_db = []
        healthy_seq = self.get_healthy_seq()
        for sys_calls in prog_log:
            windows = self.chunk_window(sys_calls, window_size)
            vec = self.get_hamming_dist(windows, healthy_seq)
            prog_db.append(vec)

        return prog_db
