#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mips import MIPS


class Assembler(object):

    def __init__(self, instructions):

        self.instructions = instructions
        self.MIPS = MIPS()

    def assemble(self):

        for instruction in self.instructions:
            self.parse_line(instruction["instruction"])

    def parse_line(self, line):

        getattr(self.MIPS, line[0].lower())(line)
