#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint

from mips import MIPS, MIPSSET


class Assembler(object):

    def __init__(self, instructions, datamem):

        self.INST = instructions
        self.MIPS = MIPS(datamem, [None] * 32)
        self.TABLE = [i["instruction"] for i in self.INST]

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                # print label, "at", line_num
                return line_num

    def calculate_cycle(self, inst):

        from random import randint
        return randint(1, 50)

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        pprint(self.MIPS.DATAMEM)
        while file_size != prog_ctr:
            prog_ctr = self.parse_line(
                self.INST[prog_ctr]["label"],
                self.INST[prog_ctr]["instruction"], prog_ctr
            )
            print self.MIPS.REG

        pprint(self.MIPS.DATAMEM)
        pprint(self.TABLE)

    def parse_line(self, label, line, prog_ctr):

        opcode, reg = line[0], line[1:]
        print "\x1b[6;30;44m", line, "\x1b[0m"

        if opcode == "BEQ":
            if self.MIPS.branch_eq(reg, prog_ctr):
                prog_ctr = self.get_label_line(reg[-1])
            else:
                prog_ctr += 1

        elif opcode == "BNE":
            if self.MIPS.branch_neq(reg, prog_ctr):
                prog_ctr = self.get_label_line(reg[-1])
            else:
                prog_ctr += 1

        elif opcode == "J":
            self.MIPS.jump(reg, prog_ctr)
            prog_ctr = self.get_label_line(reg[-1])

        elif opcode == "HLT":
            self.MIPS.halt(reg, prog_ctr)
            prog_ctr += 1

        else:

            try:
                getattr(self.MIPS, MIPSSET[opcode]["func"])(reg, prog_ctr)
                prog_ctr += 1

            except KeyError:
                raise SystemExit("Invalid opcode: " + opcode)

        return prog_ctr
