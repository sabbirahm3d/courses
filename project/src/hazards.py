#!/usr/bin/env python
# -*- coding: utf-8 -*-


STAGES = {
    "IF": None,
    "ID": None,
    "EX4": None,
    "MEM": None,
    "WB": None
}


class Hazards(object):

    def __init__(self, clock_cycles):

        self.clock_cycles = clock_cycles
        self.i_miss = "IMISS"
        self.d_miss = "DMISS"

    def get_current_stage(self, row_num, col_num):
        """
        Forwarding
        • EX2, EX3, EX4 -> EX1
        • EX1, EX2, EX3, EX4 -> ID
        • MEM -> EX1, ID
        """

        # if there was an instruction cache miss in the current
        # cycle
        if self.i_miss in self.clock_cycles[row_num][:col_num] or \
                self.d_miss in self.clock_cycles[row_num][:col_num]:
            return "WAIT"

        # if previous instruction is in a fetch stage
        elif self.clock_cycles[row_num][col_num - 1] == "IF":
            return "WAIT"

        # if previous instruction is in a decoding stage or the
        # previous cycle was in a fetch stage
        elif self.clock_cycles[row_num - 1][col_num] == self.i_miss or \
                self.clock_cycles[row_num][col_num - 1] == "ID":
            return "IF"

        elif self.clock_cycles[row_num - 1][col_num] == "IF" or \
                self.clock_cycles[row_num][col_num - 1] == "EX1":
            return "ID"

        elif self.clock_cycles[row_num - 1][col_num] == "ID" or \
                self.clock_cycles[row_num][col_num - 1] == "EX2":
            return "EX1"

        elif self.clock_cycles[row_num - 1][col_num] == "EX1" or \
                self.clock_cycles[row_num][col_num - 1] == "EX3":
            return "EX2"

        elif self.clock_cycles[row_num - 1][col_num] == "EX2" or \
                self.clock_cycles[row_num][col_num - 1] == "EX4":
            return "EX3"

        elif self.clock_cycles[row_num - 1][col_num] == "EX3" or \
                self.clock_cycles[row_num][col_num - 1] == "MEM":
            return "EX4"

        elif self.clock_cycles[row_num - 1][col_num] == "EX4" or \
            self.clock_cycles[row_num - 1][col_num] == self.d_miss or \
                self.clock_cycles[row_num][col_num - 1] == "WB":
            return "MEM"

        elif self.clock_cycles[row_num - 1][col_num] == "MEM":
            return "WB"
