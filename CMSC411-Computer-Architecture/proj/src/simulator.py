#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function

from sys import argv

from architecture.assembler import STAGES, Assembler

INSTMEM = [None] * 32
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
                        "inst": instruction,
                        "comment": "".join(inst[1:]),
                        "label": label,
                        "cycles": STAGES.copy()
                    }
                    addr += 1

    except IOError:
        raise SystemExit("Please provide a valid input instructions file")


def dump_table(table, file_name="output.txt"):

    col_names = ("Cycle Number for Each Stage",
                 "IF", "ID", "EX4", "MEM", "WB")
    inst_fmt = "{:<32}"
    row_fmt = "{:<8}" * (len(col_names))

    stat_str = (
        "Total number of access requests for instruction cache: ",
        "Number of instruction cache hits: ",
        "Total number of access requests for data cache: ",
        "Number of data cache hits: "
    )

    with open(file_name, "w") as output_file:

        print(
            inst_fmt.format(col_names[0]),
            row_fmt.format("", *col_names[1:]),
            file=output_file
        )

        for inst in table[:-1]:
            if inst["label"]:
                inst_str = "{:<8}".format(inst["label"] + ": ") + \
                    " ".join(inst["inst"])
            else:
                inst_str = "{:<8}".format(" ") + " ".join(inst["inst"])

            cycles = []
            for stage in col_names[1:]:
                cycles.append(inst["cycles"][stage])

            print(
                inst_fmt.format(inst_str), row_fmt.format("", *cycles),
                file=output_file
            )

        for index, line in enumerate(stat_str):
            print(line + table[-1][index], file=output_file)


if __name__ == "__main__":

    if len(argv) != 4:
        raise SystemExit("Please provide all the required input files")

    else:
        parse_inst(argv[1])
        SYSMEM = INSTMEM + init_mem(argv[2])

        asm_obj = Assembler(SYSMEM)
        asm_obj.assemble()
        asm_obj.compute_cycle()
        asm_obj.stats()

        dump_table(asm_obj.INST, argv[3])
