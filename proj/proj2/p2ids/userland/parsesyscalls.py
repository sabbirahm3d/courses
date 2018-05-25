#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from config import SYS_CALLS_TABLE_PATH
from util import read_data, write_data

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

    write_data(SYS_CALLS_TABLE_PATH, sys_calls)


def get_sys_call_names():

    return read_data(SYS_CALLS_TABLE_PATH)


if __name__ == '__main__':

    parse_sys_calls()
