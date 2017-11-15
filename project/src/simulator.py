#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint
from sys import argv

from assembler import Assembler

INSTMEM = [None] * 25
SYSMEM = [None] * 32


def init_mem(mem_file_path):

    try:

        with open(mem_file_path) as mem_file:
            return mem_file.read().split("\n")

    except IOError:
        raise SystemExit("Please provide a valid input data file")


def parse_inst(inst_file_path):

    addr = 0

    try:

        with open(inst_file_path) as inst_file:

            content = inst_file.read().upper()
            split_comments = [i.partition("#") for i in content.split("\n")]

            for inst in split_comments:

                instruction = inst[0].split(":")
                label = ""

                if len(instruction) == 2:
                    label, instruction = instruction

                instruction = "".join(instruction).split()
                if instruction:
                    INSTMEM[addr] = {
                        "instruction": instruction,
                        "comment": "".join(inst[1:]),
                        "label": label
                    }
                    addr += 1

    except IOError:
        raise SystemExit("Please provide a valid input instructions file")


def output_formatter(table):

    col_names = ("Cycle number for each stage",
                 "IF", "ID", "EX4", "MEM", "WB")
    inst_fmt = "{:>32}" * 2
    row_fmt = "{:>8}" * (len(col_names))
    print inst_fmt.format(
        "", *col_names[0:2]
    ), row_fmt.format(
        "", *col_names[1:]
    )

    for inst, _if, _id, _ex4, _mem, _wb in zip(
            table, range(12), range(12), range(12), range(12), range(12)):
        print inst_fmt.format(
            "", " ".join(inst)
        ), row_fmt.format(
            "", _if, _id, _ex4, _mem, _wb
        )


if __name__ == "__main__":

    if len(argv) != 4:
        raise SystemExit("Please provide all the required input files")

    else:
        instructions = parse_inst(argv[1])
        SYSMEM = INSTMEM + init_mem(argv[2])

        obj = Assembler(SYSMEM)
        obj.assemble()
