#!/usr/bin/env python
# -*- coding: utf-8 -*-

INSTRUCTIONS = {
    "J": {"cycle": 0},
    "BEQ": {"cycle": 0},
    "BNE": {"cycle": 0},
    "LI": {"cycle": 0},
    "LUI": {"cycle": 0},
    "AND": {"cycle": 1},
    "ANDI": {"cycle": 1},
    "OR": {"cycle": 1},
    "ORI": {"cycle": 1},
    "LW": {"cycle": 1},
    "SW": {"cycle": 1},
    "ADD": {"cycle": 2},
    "ADDI": {"cycle": 2},
    "SUB": {"cycle": 2},
    "SUBI": {"cycle": 2},
    "MULT": {"cycle": 4},
    "MULTI": {"cycle": 4},
}
