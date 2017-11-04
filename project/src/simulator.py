#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint
from sys import argv

from instructions import INSTRUCTIONS


def parse_inst(inst_file_path):

    instructions = []

    try:

        with open(inst_file_path) as inst_file:
            content = inst_file.read().upper()
            split_comments = [i.partition('#') for i in content.split("\n")]
            for inst in split_comments:
                instruction = inst[0].split(":")
                label = ""
                if len(instruction) == 2:
                    label, instruction = instruction
                instructions.append(
                    {
                        "instruction": "".join(instruction).split(),
                        "comment": ''.join(inst[1:]),
                        "label": label
                    }
                )

            pprint(instructions)

    except IOError:
        raise SystemExit("Please provide a valid input instructions file.")


if __name__ == "__main__":

    if len(argv) != 4:
        raise SystemExit("Please provide the instructions input file.")

    else:
        parse_inst(argv[1])
