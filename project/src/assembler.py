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
        self.CLKCYCLE = []

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                return line_num

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        # pprint(self.MIPS.DATAMEM)
        while file_size != prog_ctr:
            self.UNROLLEDINST.append(self.INST[prog_ctr]["instruction"])
            prog_ctr = self.parse_line(
                self.INST[prog_ctr]["label"],
                self.INST[prog_ctr]["instruction"],
                prog_ctr
            )

    def parse_line(self, label, line, prog_ctr):

        opcode, reg = line[0], line[1:]
        # print "\x1b[6;30;44m" + " ".join(line) + "\x1b[0m"

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

    def compute_cycle(self):

        if not self.UNROLLEDINST:
            raise SystemExit(
                "Assemble instructions before computing their clock cycles.")

        pprint(self.UNROLLEDINST)

        num_rows = 60
        num_cols = len(self.UNROLLEDINST)
        self.CLKCYCLE = [([None] * num_cols) for row in xrange(num_rows)]

        mod4_inst = [i for i in xrange(num_cols) if not i % 4]
        i_cache_miss_ctr = 11

        for row_num, row in enumerate(self.CLKCYCLE):

            for col_num, col in enumerate(self.CLKCYCLE[row_num]):

                """
                Forwarding
                • MEM, EX 2, 3 -> EX 1
                • MEM, EX 1, 2, 3 -> ID
                • MEM -> MEM
                """

                # if there was an instruction cache miss in the current
                # cycle
                if "IMISS" in row[:col_num]:
                    row[col_num] = "WAIT"

                # if previous instruction is in a fetch stage
                elif "IF" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "WAIT"

                # if previous instruction is in a decoding stage or the
                # previous cycle was in a fetch stage
                elif "IMISS" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "ID" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "IF"

                elif "IF" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "EX1" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "ID"

                elif "ID" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "EX2" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "EX1"

                elif "EX1" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "EX3" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "EX2"

                elif "EX2" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "EX4" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "EX3"

                elif "EX3" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "MEM" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "EX4"

                elif "EX4" == self.CLKCYCLE[row_num - 1][col_num] \
                        or "WB" == self.CLKCYCLE[row_num][col_num - 1]:
                    row[col_num] = "MEM"

                elif "MEM" == self.CLKCYCLE[row_num - 1][col_num]:
                    row[col_num] = "WB"

                if mod4_inst and i_cache_miss_ctr and col_num == mod4_inst[0] \
                        and "IF" not in row[:col_num]:

                    i_cache_miss_ctr -= 1
                    row[col_num] = "IMISS"

                    if not i_cache_miss_ctr:
                        mod4_inst.remove(col_num)
                        i_cache_miss_ctr = 12

    def stats(self):

        row_fmt = "{:<12}" * 13
        print self.UNROLLEDINST
        for i, j in enumerate(self.CLKCYCLE):
            print row_fmt.format("", *([i + 1] + j))

        self.data = []
        # for i, j in enumerate(self.UNROLLEDINST):
        #     cur_inst = self.INST[i]
        #     if cur_inst["instruction"] in self.UNROLLEDINST:
        #         data = " ".join(cur_inst["instruction"])
        #         if cur_inst["label"]:
        #             data = "{:<8}".format(cur_inst["label"] + ": ") + data
        #         self.data.append([data, []])

        # print self.data

        for i, j in enumerate(self.UNROLLEDINST[::-1]):
            print self.UNROLLEDINST[len(self.UNROLLEDINST) - 1 - i], j


"""
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
"""
