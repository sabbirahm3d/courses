#!/usr/bin/env python
# -*- coding: utf-8 -*-

MIPS_SET = {
    "HLT": {"cycle": -1, "opands": ()},
    "J": {"cycle": 0, "opands": ("addr")},
    "BEQ": {"cycle": 0, "opands": ("rs", "rt", "imm")},
    "BNE": {"cycle": 0, "opands": ("rs", "rt", "imm")},
    "LI": {"cycle": 0, "opands": ("rs", "rt", "imm")},
    "LUI": {"cycle": 0, "opands": ("rs", "rt", "imm")},
    "AND": {"cycle": 1, "opands": ("rs", "rt", "rd")},
    "ANDI": {"cycle": 1, "opands": ("rs", "rt", "imm")},
    "OR": {"cycle": 1, "opands": ("rs", "rt", "rd")},
    "ORI": {"cycle": 1, "opands": ("rs", "rt", "imm")},
    "LW": {"cycle": 1, "opands": ("rs", "rt", "imm")},
    "SW": {"cycle": 1, "opands": ("rs", "rt", "imm")},
    "ADD": {"cycle": 2, "opands": ("rs", "rt", "rd")},
    "ADDI": {"cycle": 2, "opands": ("rs", "rt", "imm")},
    "SUB": {"cycle": 2, "opands": ("rs", "rt", "rd")},
    "SUBI": {"cycle": 2, "opands": ("rs", "rt", "imm")},
    "MULT": {"cycle": 4, "opands": ("rs", "rt", "rd")},
    "MULTI": {"cycle": 4, "opands": ("rs", "rt", "imm")},
}


class MIPS(object):

    def __init__(self):

        pass

    @staticmethod
    def hlt(ops):

        print MIPS_SET["HLT"], ops

    @staticmethod
    def j(ops):

        print MIPS_SET["J"], ops

    @staticmethod
    def beq(ops):

        print MIPS_SET["BEQ"], ops

    @staticmethod
    def bne(ops):

        print MIPS_SET["BNE"], ops

    @staticmethod
    def li(ops):

        print MIPS_SET["LI"], ops
