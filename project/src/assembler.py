#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mips import MIPS, MIPSSET


class Assembler(object):

    def __init__(self, instructions, instmem, datamem):

        self.instructions = instructions
        self.registers = [None] * 32
        self.MIPS = MIPS(instmem, datamem, self.registers)

    def assemble(self):

        for instruction in self.instructions:
            self.parse_line(instruction["instruction"])

    def parse_line(self, line):

        getattr(self.MIPS, MIPSSET[line[0]]["func"])(line[1:])
