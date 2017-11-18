#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint

from mips import MIPS, MIPSSET


class Assembler(object):

    def __init__(self, sys_memory):

        self.INST = filter(None, sys_memory[:25])
        self.MIPS = MIPS(sys_memory, [None] * 32)
        self.TABLE = [[i["label"], i["instruction"]] for i in self.INST]
        self.CLKCYCLE = self.NUMINST = len(self.INST)

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                # print label, "at", line_num
                return line_num

    def calculate_cycle(self, inst):

        def get_if_cycle(cycle):

            return cycle + 1

        def get_id_cycle(cycle):

            return cycle + 1

        def get_ex4_cycle(cycle):

            return cycle + 1

        def get_mem_cycle(cycle):

            return cycle + 1

        def get_wb_cycle(cycle):

            return cycle + 1

        cycles = []
        for func in (
            get_if_cycle, get_id_cycle,
            get_ex4_cycle, get_mem_cycle,
            get_wb_cycle
        ):
            self.CLKCYCLE = func(self.CLKCYCLE)
            cycles.append(self.CLKCYCLE)

        return cycles

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        pprint(self.MIPS.DATAMEM)
        while file_size != prog_ctr:
            prog_ctr = self.parse_line(
                self.INST[prog_ctr]["label"],
                self.INST[prog_ctr]["instruction"],
                prog_ctr
            )
            self.TABLE[(prog_ctr - 1) % self.NUMINST].append(
                self.calculate_cycle(
                    self.INST[(prog_ctr - 1) % self.NUMINST]["instruction"][0]
                )
            )
            # self.TABLE.append(prog_ctr)
            print self.MIPS.REG

        # pprint(self.MIPS.DATAMEM)
        pprint(self.TABLE)

    def parse_line(self, label, line, prog_ctr):

        opcode, reg = line[0], line[1:]
        print "\x1b[6;30;44m", line, "\x1b[0m"

        # conditional branches
        if opcode in {"BEQ", "BNE"}:
            if getattr(self.MIPS, MIPSSET[opcode]["func"])(reg, prog_ctr):
                prog_ctr = self.get_label_line(reg[-1])
            else:
                prog_ctr += 1

        # unconditional branch
        elif opcode == "J":
            self.MIPS.jump(reg, prog_ctr)
            prog_ctr = self.get_label_line(reg[-1])

        # halt
        elif opcode == "HLT":
            self.MIPS.halt(reg, prog_ctr)
            prog_ctr += 1

        else:

            try:
                # other opcodes
                getattr(self.MIPS, MIPSSET[opcode]["func"])(reg, prog_ctr)
                prog_ctr += 1

            except KeyError:
                # unsupported opcode
                raise SystemExit("Invalid opcode: " + opcode)

        return prog_ctr
