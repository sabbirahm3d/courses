#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint

from mips import MIPS, MIPSSET


class Hazards(object):

    def __init__(self):

        pass

    # @staticmethod
    # def inst_cache_miss(row_num, col_num, cycle):

    #     if not row_num % 4:


class Assembler(object):

    def __init__(self, sys_memory):

        self.INST = filter(None, sys_memory[:25])
        self.MIPS = MIPS(sys_memory, [None] * 32)
        self.TABLE = [[i["label"], i["instruction"]] for i in self.INST]
        self.UNROLLEDINST = []
        self.CLKCYCLE = self.NUMINST = len(self.INST)

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                return line_num

    # def calculate_cycle(self, inst):

    #     def get_if_cycle(cycle):

    #         return cycle + 1

    #     def get_id_cycle(cycle):

    #         return cycle + 1

    #     def get_ex4_cycle(cycle):

    #         return cycle + 1

    #     def get_mem_cycle(cycle):

    #         return cycle + 1

    #     def get_wb_cycle(cycle):

    #         return cycle + 1

    #     cycles = []
    #     for func in (
    #         get_if_cycle, get_id_cycle,
    #         get_ex4_cycle, get_mem_cycle,
    #         get_wb_cycle
    #     ):
    #         self.CLKCYCLE = func(self.CLKCYCLE)
    #         cycles.append(self.CLKCYCLE)

    #     return cycles

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        pprint(self.MIPS.DATAMEM)
        while file_size != prog_ctr:
            self.UNROLLEDINST.append(self.INST[prog_ctr]["instruction"])
            prog_ctr = self.parse_line(
                self.INST[prog_ctr]["label"],
                self.INST[prog_ctr]["instruction"],
                prog_ctr
            )
            # self.TABLE[(prog_ctr - 1) % self.NUMINST].append(
            #     self.calculate_cycle(
            #         self.INST[(prog_ctr - 1) % self.NUMINST]["instruction"][0]
            #     )
            # )
            # self.TABLE.append(prog_ctr)
            print self.MIPS.REG

        # pprint(self.MIPS.DATAMEM)
        # pprint(self.TABLE)

    def compute_cycle(self):

        self.UNROLLEDINST = [[i, 100 * [None]] for i in self.UNROLLEDINST]

        unrolled_iter = xrange(len(self.UNROLLEDINST))

        i_cache_misses = 1
        for row in unrolled_iter:

            i_cache_miss_ctr = (i_cache_misses * 12) - 1
            stage = 5
            cur_inst = MIPSSET[self.UNROLLEDINST[row][0][0]]
            ex_stages = cur_inst["cycle"]

            row_iter = xrange(len(self.UNROLLEDINST[row][-1]))
            for col in row_iter:

                if not row % 4 and i_cache_miss_ctr:
                    if i_cache_miss_ctr:
                        self.UNROLLEDINST[row][-1][col] = "WAIT"
                        i_cache_miss_ctr -= 1

                    if not i_cache_miss_ctr:
                        i_cache_misses += 1

                else:

                    if self.UNROLLEDINST[row - 1][-1][col] == "WAIT":
                        self.UNROLLEDINST[row][-1][col] = "WAIT"

                    elif self.UNROLLEDINST[row - 1][-1][col] == "IF":
                        self.UNROLLEDINST[row][-1][col] = "WAIT"

                    else:

                        if not ex_stages and stage == 3:
                            stage -= 1

                        if stage == 5:
                            self.UNROLLEDINST[row][-1][col] = "IF"

                        elif stage == 4:
                            self.UNROLLEDINST[row][-1][col] = "ID"

                        elif stage == 3:

                            if ex_stages > 0:
                                self.UNROLLEDINST[row][-1][col] = "EX" + \
                                    str(cur_inst["cycle"] - ex_stages + 1)
                                ex_stages -= 1
                                stage += 1

                        elif stage == 2:
                            self.UNROLLEDINST[row][-1][col] = "MEM"

                        elif stage == 1:
                            self.UNROLLEDINST[row][-1][col] = "WB"
                            break

                        stage -= 1

                    print \
                        col, \
                        self.UNROLLEDINST[row - 1][0], \
                        self.UNROLLEDINST[row - 1][-1][col], \
                        self.UNROLLEDINST[row][0], \
                        self.UNROLLEDINST[row][-1][col]

        pprint(self.UNROLLEDINST)

    def parse_line(self, label, line, prog_ctr):

        opcode, reg = line[0], line[1:]
        print "\x1b[6;30;44m" + " ".join(line) + "\x1b[0m"

        # conditional branches
        if opcode in {"BEQ", "BNE"}:
            if getattr(self.MIPS, MIPSSET[opcode]["func"])(reg, prog_ctr):
                prog_ctr = self.get_label_line(reg[-1])
            else:
                prog_ctr += 1

        # unconditional branch
        elif opcode == "J":
            prog_ctr = self.get_label_line(reg[-1])

        # halt
        elif opcode == "HLT":
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
