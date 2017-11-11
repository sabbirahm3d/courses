#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint
from sys import argv

from assembler import Assembler

INSTMEM = [None] * 100
DATAMEM = [None] * 32


def init_mem(mem_file_path):

    try:

        with open(mem_file_path) as mem_file:
            return mem_file.read().split("\n")

        # print DATAMEM

    except IOError:
        raise SystemExit("Please provide a valid input data file")


def parse_inst(inst_file_path):

    instructions = []

    try:

        with open(inst_file_path) as inst_file:

            content = inst_file.read().upper()
            split_comments = [i.partition("#") for i in content.split("\n")]

            for inst in split_comments:

                instruction = inst[0].split(":")
                label = ""

                if len(instruction) == 2:
                    label, instruction = instruction

                instructions.append(
                    {
                        "instruction": "".join(instruction).split(),
                        "comment": "".join(inst[1:]),
                        "label": label
                    }
                )

            return [inst for inst in instructions if inst["instruction"]]

    except IOError:
        raise SystemExit("Please provide a valid input instructions file")


if __name__ == "__main__":

    if len(argv) != 4:
        raise SystemExit("Please provide all the required input files")

    else:
        instructions = parse_inst(argv[1])
        DATAMEM = init_mem(argv[2])

        # print instructions
        obj = Assembler(instructions, INSTMEM, DATAMEM)
        obj.assemble()
