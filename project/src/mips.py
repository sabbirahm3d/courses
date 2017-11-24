#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re

MIPSSET = {
    "HLT": {"cycle": 0, "func": "halt"},
    "J": {"cycle": 0, "func": "jump"},
    "BEQ": {"cycle": 0, "func": "branch_eq"},
    "BNE": {"cycle": 0, "func": "branch_neq"},
    "LI": {"cycle": 0, "func": "load_imm"},
    "LUI": {"cycle": 0, "func": "load_up_imm"},
    "AND": {"cycle": 1, "func": "and_reg"},
    "ANDI": {"cycle": 1, "func": "and_imm"},
    "OR": {"cycle": 1, "func": "or_reg"},
    "ORI": {"cycle": 1, "func": "or_imm"},
    "LW": {"cycle": 1, "func": "load_word"},
    "SW": {"cycle": 1, "func": "store_word"},
    "ADD": {"cycle": 2, "func": "add_reg"},
    "ADDI": {"cycle": 2, "func": "add_imm"},
    "SUB": {"cycle": 2, "func": "sub_reg"},
    "SUBI": {"cycle": 2, "func": "sub_imm"},
    "MULT": {"cycle": 4, "func": "mult_reg"},
    "MULTI": {"cycle": 4, "func": "mult_imm"},
}

reg_pat = re.compile("(?<=R)\d{,2}")
offset_pat = re.compile("\d{,2}(?=\()")


def parse_reg(rt):

    return to_dec(reg_pat.search(rt).group())


def parse_offset(offset):

    return int(offset_pat.search(offset).group())


def to_dec(num):

    if "H" in num:
        return int(num.replace("H", ""), 16)

    return int(num)


def hex_to_dec_to_hex(num):

    return int(hex(num)[2:])


class MIPS(object):

    def __init__(self, datamem, registers):

        self.DATAMEM = datamem
        self.REG = registers

    def parse_addr(self, addr):

        if "(" in addr:
            return (
                parse_offset(addr) +
                hex_to_dec_to_hex(self.REG[parse_reg(addr)]) / 4
            )

        return to_dec(addr)

    def and_reg(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        rt = parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] & self.REG[rt]

    def and_imm(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] & imm

    def or_reg(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        rt = parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] | self.REG[rt]

    def or_imm(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] | imm

    def add_reg(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        rt = parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] + self.REG[rt]

    def add_imm(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] + imm

    def sub_reg(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        rt = parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] - self.REG[rt]

    def sub_imm(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] - imm

    def mult_reg(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        rt = parse_reg(ops[2])

        self.REG[rd] = self.REG[rs] * self.REG[rt]

    def mult_imm(self, ops, prog_ctr):

        rd = parse_reg(ops[0])
        rs = parse_reg(ops[1])
        imm = self.parse_addr(ops[2])

        self.REG[rd] = self.REG[rs] * imm

    def load_imm(self, ops, prog_ctr):

        rt = parse_reg(ops[0])
        addr = self.parse_addr(ops[-1])
        self.REG[rt] = addr
        # print

    def load_up_imm(self, ops, prog_ctr):

        rt = parse_reg(ops[0])
        addr = self.parse_addr(ops[-1]) << 16
        self.REG[rt] = addr
        # print '{:032b}'.format(addr)

    def load_word(self, ops, prog_ctr):

        rt = parse_reg(ops[0])
        self.REG[rt] = int(self.DATAMEM[self.parse_addr(ops[-1])], 2)

    def store_word(self, ops, prog_ctr):

        rt = parse_reg(ops[0])
        rs = self.parse_addr(ops[-1])
        self.DATAMEM[rs] = '{:032b}'.format(self.REG[rt])

    def branch_eq(self, ops, prog_ctr):

        rs = parse_reg(ops[0])
        rt = parse_reg(ops[1])
        # print self.REG[rs], self.REG[rt], self.REG[rs] == self.REG[rt]
        return self.REG[rs] == self.REG[rt]

    def branch_neq(self, ops, prog_ctr):

        rs = parse_reg(ops[0])
        rt = parse_reg(ops[1])
        # print self.REG[rs], self.REG[rt], self.REG[rs] != self.REG[rt]
        return self.REG[rs] != self.REG[rt]

    def jump(self, ops, prog_ctr):

        return None

    def halt(self, ops, prog_ctr):

        return None
