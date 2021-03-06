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
        self.INSTREQS = 0
        self.INSTHITS = 0
        self.DATAREQS = 0
        self.DATAHITS = -1

    def get_label_line(self, label):

        for line_num, line in enumerate(self.INST):
            if label == line["label"]:
                return line_num

    def assemble(self):

        file_size = len(self.INST)
        prog_ctr = 0

        while prog_ctr != file_size:
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
        hazards = Hazards(self.CLKCYCLE, self.UNROLLEDINST)
        mod4_inst = [i for i in xrange(num_cols) if not i % 4]

        self.INSTREQS = num_cols
        self.INSTHITS = num_cols - len(mod4_inst)

        mem_inst = 0
        for inst in xrange(num_cols):
            if hazards.is_data_miss(inst):
                mem_inst += 1

        inst_miss_ctr = 11
        data_miss_ctr = 11
        data_stall = False

        for row_num, row in enumerate(self.CLKCYCLE):

            for col_num, col in enumerate(self.CLKCYCLE[row_num]):

                row[col_num] = hazards.get_current_stage(
                    row_num=row_num,
                    col_num=col_num
                )

                if data_stall and row[col_num] == "MEM":
                    row[col_num] = self.CLKCYCLE[row_num - 1][col_num]

                if mem_inst and data_miss_ctr and \
                        hazards.is_data_miss(col_num) and \
                        self.CLKCYCLE[row_num - 1][col_num] in \
                        {"EX4", hazards.data_miss}:

                    data_stall = True
                    data_miss_ctr -= 1
                    row[col_num] = hazards.data_miss

                    if not data_miss_ctr:
                        mem_inst -= 1
                        data_miss_ctr = 12
                        data_stall = False
                        self.DATAREQS += 1
                        self.DATAHITS += 1

                if mod4_inst and inst_miss_ctr \
                    and col_num == mod4_inst[0] \
                        and "IF" not in row[:col_num]:

                    data_miss_ctr = 12
                    inst_miss_ctr -= 1
                    row[col_num] = hazards.inst_miss

                    if not inst_miss_ctr:
                        mod4_inst.remove(col_num)
                        inst_miss_ctr = 12

    def stats(self):

        # for debugging purposes only - uncomment the following snippet to view
        # the two-dimensional representation of the clock cycles
        # row_fmt = "{:<8}" * (len(self.UNROLLEDINST) + 2)
        # for i, j in enumerate(self.CLKCYCLE):
        #     print row_fmt.format("", *([i + 1] + j))

        for clk_cycle, unrolled_inst in enumerate(self.CLKCYCLE):

            for stage in STAGES.keys():

                if stage in unrolled_inst:
                    for inst in self.INST:

                        if inst["inst"] == \
                                self.UNROLLEDINST[unrolled_inst.index(stage)]:
                            inst["cycles"][stage] = clk_cycle + 1

        halt_flag = 0
        halt_cycles = []
        reversed_inst = self.INST[::-1]

        for index, inst in enumerate(reversed_inst):
            for stage, cycle in inst["cycles"].items():

                if inst["inst"][0] == "HLT":
                    if not halt_flag and cycle:

                        halt_cycles.append(cycle - 1)

                        if len(halt_cycles) == 2:
                            inst["cycles"][stage] = ""
                        else:
                            inst["cycles"][stage] = \
                                reversed_inst[index + 1]["cycles"]["IF"] + 1

                    else:
                        if inst["cycles"][stage]:
                            inst["cycles"][stage] = halt_cycles.pop(0)

                if not cycle:
                    inst["cycles"][stage] = ""

            halt_flag = 1

        self.INST.append(
            (
                str(self.INSTREQS),
                str(self.INSTHITS),
                str(self.DATAREQS),
                str(self.DATAHITS),
            )
        )
