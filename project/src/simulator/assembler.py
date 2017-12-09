#!/usr/bin/env python
# -*- coding: utf-8 -*-

from pprint import pprint

from hazards import STAGES, Hazards
from mips import MIPS, MIPSSET


class Assembler(object):

    def __init__(self, sys_memory):

        self.INST = filter(None, sys_memory[:25])
        self.MIPS = MIPS(sys_memory, [None] * 32)
        self.UNROLLEDINST = []
        self.CLKCYCLE = []
        self.IREQS = 0
        self.IHITS = 0
        self.DREQS = 0
        self.DHITS = -1

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                return line_num

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        # pprint(self.MIPS.DATAMEM)
        while file_size != prog_ctr:
            self.UNROLLEDINST.append(self.INST[prog_ctr]["inst"])
            prog_ctr = self.parse_line(
                self.INST[prog_ctr]["label"],
                self.INST[prog_ctr]["inst"],
                prog_ctr
            )

    def parse_line(self, label, line, prog_ctr):

        opcode, reg = line[0], line[1:]

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

        num_cols = len(self.UNROLLEDINST)
        num_rows = 10 * num_cols
        self.CLKCYCLE = [([None] * num_cols) for row in xrange(num_rows)]
        hazards = Hazards(self.CLKCYCLE, self.UNROLLEDINST, self.MIPS.REG)
        mod4_inst = [i for i in xrange(num_cols) if not i % 4]

        self.IREQS = num_cols
        self.IHITS = num_cols - len(mod4_inst)

        mem_inst = 0
        for inst in xrange(num_cols):
            if hazards.is_data_miss(inst):
                mem_inst += 1

        i_cache_miss_ctr = 11
        d_cache_miss_ctr = 11
        dstall = False
        pprint(self.MIPS.REG)

        for row_num, row in enumerate(self.CLKCYCLE):

            for col_num, col in enumerate(self.CLKCYCLE[row_num]):

                row[col_num] = hazards.get_current_stage(
                    row_num=row_num,
                    col_num=col_num
                )

                if dstall and row[col_num] == "MEM":
                    row[col_num] = self.CLKCYCLE[row_num - 1][col_num]

                if mem_inst and d_cache_miss_ctr and \
                        hazards.is_data_miss(col_num) and \
                        self.CLKCYCLE[row_num - 1][col_num] in \
                        {"EX4", hazards.d_miss}:

                    dstall = True
                    d_cache_miss_ctr -= 1
                    row[col_num] = hazards.d_miss

                    if not d_cache_miss_ctr:
                        mem_inst -= 1
                        d_cache_miss_ctr = 12
                        dstall = False
                        self.DREQS += 1
                        self.DHITS += 1

                if mod4_inst and i_cache_miss_ctr and col_num == mod4_inst[0] \
                        and "IF" not in row[:col_num]:

                    d_cache_miss_ctr = 12
                    i_cache_miss_ctr -= 1
                    row[col_num] = hazards.i_miss

                    if not i_cache_miss_ctr:
                        mod4_inst.remove(col_num)
                        i_cache_miss_ctr = 12

    def stats(self):

        row_fmt = "{:<8}" * (len(self.UNROLLEDINST) + 2)
        for i, j in enumerate(self.CLKCYCLE):
            print row_fmt.format("", *([i + 1] + j))

        for clk_cycle, unrolled_inst in enumerate(self.CLKCYCLE):

            for stage in STAGES.keys():

                if stage in unrolled_inst:
                    for inst in self.INST:

                        if inst["inst"][0] in {"BNE", "BEQ", "J", "HLT"} and \
                                stage not in {"IF", "ID"}:
                            inst["cycles"][stage] = None
                            break

                        elif inst["inst"] == \
                                self.UNROLLEDINST[unrolled_inst.index(stage)]:
                            inst["cycles"][stage] = clk_cycle + 1
                            break

        for inst in self.INST:
            for stage, cycle in inst["cycles"].items():
                if not cycle:
                    inst["cycles"][stage] = ""

        self.INST.append(
            (
                str(self.IREQS),
                str(self.IHITS),
                str(self.DREQS),
                str(self.DHITS),
            )
        )
