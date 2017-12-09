#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mips import MIPSSET

STAGES = {
    "IF": None,
    "ID": None,
    "EX4": None,
    "MEM": None,
    "WB": None
}


class Hazards(object):

    def __init__(self, clock_cycles, instructions, registers):

        self.clock_cycles = clock_cycles
        self.unrolled_inst = instructions
        self.REG = registers

        self.i_miss = "IMISS"
        self.d_miss = "DMISS"

    def is_data_miss(self, col_num):

        return self.unrolled_inst[col_num][0] in {"LW", "SW"}

    def data_ready(self, prev_inst_stage, cur_stage, cur_inst, prev_cycle):

        prev_inst_min = MIPSSET[self.unrolled_inst[cur_inst - 1][0]]["cycle"]

        if self.unrolled_inst[cur_inst - 1][0] == "MULT":
            if prev_inst_stage and prev_cycle:
                if "EX" in prev_inst_stage and \
                        int(prev_inst_stage[-1]) in {2, 3, 4}:
                    print "min:", prev_inst_min,
                    print " prev_inst:", prev_inst_stage,
                    print " prev_cycle:", prev_cycle,
                    print " ready?", prev_inst_min <= int(prev_inst_stage[-1])
                    return prev_inst_min < int(prev_inst_stage[-1])

        return True

    def get_current_stage(self, row_num, col_num):
        """
        Forwarding
        • EX2, EX3, EX4 -> EX1
        • EX1, EX2, EX3, EX4 -> ID
        • MEM -> EX1, ID
        """

        prev_inst_stage = self.clock_cycles[row_num][col_num - 1]
        prev_cycle = self.clock_cycles[row_num - 1][col_num]
        cur_stage = self.clock_cycles[row_num][col_num]

        if not self.data_ready(
            prev_inst_stage=prev_inst_stage,
            cur_stage=cur_stage,
            cur_inst=col_num,
            prev_cycle=prev_cycle
        ):
            # print "HOOOOOOOOOOOOO", prev_cycle, prev_inst_stage
            return prev_cycle

        # if there was an instruction cache miss in the current cycle
        if self.i_miss in self.clock_cycles[row_num][:col_num] or \
                prev_inst_stage == "IF":
            return "WAIT"

        # if previous instruction is in a decoding stage or the
        # previous cycle was in a fetch stage
        elif prev_cycle == self.i_miss or prev_inst_stage == "ID":
            return "IF"

        elif prev_cycle == "IF" or prev_inst_stage == "EX1":
            return "ID"

        elif prev_cycle == "ID" or prev_inst_stage == "EX2":
            return "EX1"

        elif prev_cycle == "EX1" or prev_inst_stage == "EX3":
            return "EX2"

        elif prev_cycle == "EX2" or prev_inst_stage == "EX4":
            return "EX3"

        elif prev_cycle == "EX3" or prev_inst_stage == "MEM":
            return "EX4"

        elif prev_cycle == "EX4" or prev_cycle == self.d_miss or \
                prev_inst_stage == "WB":
            return "MEM"

        elif prev_cycle == "MEM":
            return "WB"
