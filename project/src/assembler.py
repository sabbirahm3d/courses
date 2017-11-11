#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mips import MIPS, MIPSSET


class Assembler(object):

    def __init__(self, instructions, instmem, datamem):

        self.instructions = instructions
        self.registers = [None] * 32
        self.MIPS = MIPS(instmem, datamem, self.registers)

    def get_label_line(self, label):

        for line_num, line in enumerate(self.instructions):
            if label == line["label"]:
                print label, "at", line_num
                return line_num

    def assemble(self):

        file_size = len(self.instructions)
        prog_ctr = 0

        while file_size != prog_ctr:
            prog_ctr = self.parse_line(
                self.instructions[prog_ctr]["label"],
                self.instructions[prog_ctr]["instruction"], prog_ctr
            )
            print self.MIPS.REG

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
            prog_ctr += 1

        elif opcode == "HLT":
            self.MIPS.halt(reg, prog_ctr)
            prog_ctr += 1

        else:
            getattr(self.MIPS, MIPSSET[opcode]["func"])(reg, prog_ctr)
            prog_ctr += 1

        return prog_ctr
