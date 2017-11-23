#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

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


def dump_table(table, file_name="output.txt"):

    col_names = ("Cycle Number for Each Stage",
                 "IF", "ID", "EX4", "MEM", "WB")
    inst_fmt = "{:<32}"
    row_fmt = "{:<8}" * (len(col_names))

    with open(file_name, "w") as output_file:

        print(
            inst_fmt.format(col_names[0]),
            row_fmt.format("", *col_names[1:]),
            file=output_file
        )

        for label, inst, cycles in table:
            if label:
                inst = "{:<8}".format(label + ": ") + " ".join(inst)
            else:
                inst = "{:<8}".format(" ") + " ".join(inst)

            print(
                inst_fmt.format(inst),
                row_fmt.format("", *cycles),
                file=output_file
            )


if __name__ == "__main__":

    if len(argv) != 4:
        raise SystemExit("Please provide all the required input files")

    else:
        parse_inst(argv[1])
        SYSMEM = INSTMEM + init_mem(argv[2])

        asm_obj = Assembler(SYSMEM)
        asm_obj.assemble()
        asm_obj.compute_cycle()

        # dump_table(asm_obj.TABLE, argv[3])
