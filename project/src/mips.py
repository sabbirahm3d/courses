#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re

MIPSSET = {
    "HLT": {"cycle": -1, "opands": (), "func": "halt"},
    "J": {"cycle": 0, "opands": ("addr"), "func": "jump"},
    "BEQ": {"cycle": 0, "opands": ("rs", "rt", "imm"), "func": "branch_eq"},
    "BNE": {"cycle": 0, "opands": ("rs", "rt", "imm"), "func": "branch_neq"},
    "LI": {"cycle": 0, "opands": ("rs", "rt", "imm"), "func": "load_imm"},
    "LUI": {"cycle": 0, "opands": ("rs", "rt", "imm"), "func": "load_up_imm"},
    "AND": {"cycle": 1, "opands": ("rs", "rt", "rd"), "func": "and_reg"},
    "ANDI": {"cycle": 1, "opands": ("rs", "rt", "imm"), "func": "and_imm"},
    "OR": {"cycle": 1, "opands": ("rs", "rt", "rd"), "func": "or_reg"},
    "ORI": {"cycle": 1, "opands": ("rs", "rt", "imm"), "func": "or_imm"},
    "LW": {"cycle": 1, "opands": ("rs", "rt", "imm"), "func": "load_word"},
    "SW": {"cycle": 1, "opands": ("rs", "rt", "imm"), "func": "store_word"},
    "ADD": {"cycle": 2, "opands": ("rs", "rt", "rd"), "func": "add_reg"},
    "ADDI": {"cycle": 2, "opands": ("rs", "rt", "imm"), "func": "add_imm"},
    "SUB": {"cycle": 2, "opands": ("rs", "rt", "rd"), "func": "sub_reg"},
    "SUBI": {"cycle": 2, "opands": ("rs", "rt", "imm"), "func": "sub_imm"},
    "MULT": {"cycle": 4, "opands": ("rs", "rt", "rd"), "func": "mult_reg"},
    "MULTI": {"cycle": 4, "opands": ("rs", "rt", "imm"), "func": "mult_imm"},
}


class MIPS(object):

    def __init__(self, instmem, datamem, registers):

        self.INSTMEM = instmem
        self.DATAMEM = datamem
        self.REG = registers
        self.reg_pat = re.compile("(?<=R)\d{,2}")

    @staticmethod
    def to_dec(num):

        if "H" in num:
            return int(num.replace("H", ""), 16)
        elif "B" in num:
            return int(num.replace("B", ""), 2)

        return int(num.replace("D", ""))

    def parse_reg(self, rt):

        return self.to_dec(self.reg_pat.search(rt).group())

    def parse_addr(self, addr):

        print "ADDR", addr
        if "(" in addr:
            print self.to_dec(addr[0])
            return self.REG[self.to_dec(addr[0]) + self.parse_reg(addr)]
        else:
            return self.to_dec(addr)

    def halt(self, ops):

        print MIPSSET["HLT"], ops

    def jump(self, ops):

        print MIPSSET["J"], ops

    def branch_eq(self, ops):

        print MIPSSET["BEQ"], ops

    def branch_neq(self, ops):

        print MIPSSET["BNE"], ops

    def load_imm(self, ops):

        print "\x1b[6;30;41mLOAD IMM\x1b[0m", ops
        reg = self.parse_reg(ops[0])
        print "R", reg, "MEM[", self.REG[reg], "]"
        print self.REG
        addr = self.parse_addr(ops[-1])
        self.REG[reg] = addr
        print "R", reg, "MEM[", self.REG[reg], "]"
        print self.REG
        print '{:032b}'.format(addr)
        return addr

    def load_up_imm(self, ops):

        addr = self.load_imm(ops)
        print '{:032b}'.format(addr << 16)

    def and_reg(self, ops):

        print MIPSSET["AND"], ops

    def and_imm(self, ops):

        print MIPSSET["ANDI"], ops

    def or_reg(self, ops):

        print MIPSSET["OR"], ops

    def or_imm(self, ops):

        print MIPSSET["ORI"], ops

    def load_word(self, ops):

        print "\x1b[6;30;42mLOAD WORD\x1b[0m", ops
        reg = self.parse_reg(ops[0])
        print "R", reg, "MEM[", self.REG[reg], "]"
        print self.REG
        self.REG[reg] = self.parse_addr(ops[-1])
        print "R", reg, "MEM[", self.REG[reg], "]"
        print self.REG

    def store_word(self, ops):

        print MIPSSET["SW"], ops

    def add_reg(self, ops):

        print MIPSSET["ADD"], ops

    def add_imm(self, ops):

        print MIPSSET["ADDI"], ops

    def sub_reg(self, ops):

        print MIPSSET["SUB"], ops

    def sub_imm(self, ops):

        print MIPSSET["SUBI"], ops

    def mult_reg(self, ops):

        print MIPSSET["MULT"], ops

    def mult_imm(self, ops):

        print MIPSSET["MULTI"], ops
