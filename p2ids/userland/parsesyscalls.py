#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json
from os import path

from config import SYS_CALLS_TABLE_PATH

BASE_PATH = path.abspath(__file__)
TABLE_PATH = path.join(
    path.dirname(path.dirname(path.dirname(BASE_PATH))),
    "arch", "x86", "entry", "syscalls", "syscall_64.tbl"
)


def parse_sys_calls():

    sys_calls = {}

    with open(TABLE_PATH) as table_file:
        for line in table_file:
            if not line[0] == "#" and line[0].isdigit():
                split_line = line.split()
                sys_calls[int(split_line[0])] = split_line[2]

    with open(SYS_CALLS_TABLE_PATH, "w") as dump_file:
        json.dump(sys_calls, dump_file)


def get_sys_call_names():

    with open(SYS_CALLS_TABLE_PATH) as sys_calls_table_file:
        return dict(json.load(sys_calls_table_file))


if __name__ == '__main__':

    parse_sys_calls()
