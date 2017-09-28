#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
A simulation for a proof of concept for the game logic in `main.asm`
"""


import sys

BITFORMAT = "{:08b}"

SECRET = 0b11011000
USER = 0b00000000
CURSOR = 0b00000000

u = 0b00000000
d = 0b00000001
l = 0b00000010
r = 0b00000011


def lshift(register, NSHIFT):

    register = register << 1
    register = register << 1
    NSHIFT -= 1
    if NSHIFT >= 1:
        return lshift(register, NSHIFT)
    return register


print "SECRET:", BITFORMAT.format(SECRET)
print "USER:", BITFORMAT.format(USER)
print "CURSOR:", BITFORMAT.format(CURSOR), "\n"

USER = input("input: ")
NSHIFT = 3
USER = lshift(USER, NSHIFT)
CURSOR = SECRET & 0b11000000
print "USER:", BITFORMAT.format(USER)
print "STATE0:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
NSHIFT = 2
USER = lshift(USER, NSHIFT)
CURSOR = SECRET & 0b00110000

print "USER:", BITFORMAT.format(USER)
print "STATE1:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
NSHIFT = 1
USER = lshift(USER, NSHIFT)
CURSOR = SECRET & 0b00001100

print "USER:", BITFORMAT.format(USER)
print "STATE2:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
NSHIFT = 0
USER = lshift(USER, NSHIFT)
CURSOR = SECRET & 0b00000011

print "USER:", BITFORMAT.format(USER)
print "STATE3:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")

print "\x1b[1;32;40mLED ON\x1b[0m"
