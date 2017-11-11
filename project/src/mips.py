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

        if "(" in addr:
            return self.REG[self.to_dec(addr[0]) + self.parse_reg(addr)]
        else:
            return self.to_dec(addr)

    def halt(self, ops, prog_ctr):

        # print MIPSSET["HLT"], ops
        return prog_ctr + 1

    def jump(self, ops, prog_ctr):

        # print MIPSSET["J"], ops
        return prog_ctr + 1

    def branch_eq(self, ops, prog_ctr):

        rs = self.parse_reg(ops[0])
        rt = self.parse_reg(ops[1])
        print self.REG[rs], self.REG[rt], self.REG[rs] == self.REG[rt]
        return self.REG[rs] == self.REG[rt]

    def branch_neq(self, ops, prog_ctr):

        rs = self.parse_reg(ops[0])
        rt = self.parse_reg(ops[1])
        print self.REG[rs], self.REG[rt], self.REG[rs] != self.REG[rt]
        return self.REG[rs] != self.REG[rt]

    def load_imm(self, ops, prog_ctr):

        reg = self.parse_reg(ops[0])
        addr = self.parse_addr(ops[-1])
        self.REG[reg] = addr
        # print '{:032b}'.format(addr)
        return prog_ctr + 1

    def load_up_imm(self, ops, prog_ctr):

        reg = self.parse_reg(ops[0])
        addr = self.parse_addr(ops[-1]) << 16
        self.REG[reg] = addr
        # print '{:032b}'.format(addr)
        return prog_ctr + 1

    def and_reg(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        rt = self.parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] & self.REG[rt]
        return prog_ctr + 1

    def and_imm(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] & imm
        return prog_ctr + 1

    def or_reg(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        rt = self.parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] | self.REG[rt]
        return prog_ctr + 1

    def or_imm(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] | imm
        return prog_ctr + 1

    def load_word(self, ops, prog_ctr):

        reg = self.parse_reg(ops[0])
        self.REG[reg] = self.parse_addr(ops[-1])
        return prog_ctr + 1

    def store_word(self, ops, prog_ctr):

        # print MIPSSET["SW"], ops
        return prog_ctr + 1

    def add_reg(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        rt = self.parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] + self.REG[rt]
        return prog_ctr + 1

    def add_imm(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] + imm
        return prog_ctr + 1

    def sub_reg(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        rt = self.parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] - self.REG[rt]
        return prog_ctr + 1

    def sub_imm(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] - imm
        return prog_ctr + 1

    def mult_reg(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        rt = self.parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] * self.REG[rt]
        return prog_ctr + 1

    def mult_imm(self, ops, prog_ctr):

        rd = self.parse_reg(ops[0])
        rs = self.parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] * imm
        return prog_ctr + 1
