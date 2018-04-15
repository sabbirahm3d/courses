#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from parsesyscalls import get_sys_call_names

BASE_PATH = path.abspath(__file__)


from pprint import pprint


def parse_log(log_path):

    sys_calls = {}
    get_sys_call_names()

    with open(log_path) as log_file:
        for line in log_file:
            split_line = line.split()
            if split_line[0] not in sys_calls:
                sys_calls[split_line[0]] = []
            sys_calls[split_line[0]].append(
                (split_line[2], split_line[1])
            )

    return sys_calls


def chunk_seq(seq, k):

    seq_len = len(seq)
    chunked = []
    for elem in xrange(seq_len - k + 1):
        chunked.append(seq[elem:elem + k])

    return chunked


if __name__ == '__main__':

    pprint(chunk_seq(parse_log("sample.log")["66"], 5))
