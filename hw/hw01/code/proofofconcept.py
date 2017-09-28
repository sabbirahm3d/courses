#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

BITFORMAT = "{:08b}"

SECRET = 0b00011011
USER = 0b00000000
CURSOR = 0b00000000
MASK = 0b00000010

u = 0b00000000
d = 0b00000001
l = MASK
r = 0b00000011

print "SECRET:", BITFORMAT.format(SECRET)
print "USER:", BITFORMAT.format(USER)
print "CURSOR:", BITFORMAT.format(CURSOR), "\n"

USER = input("input: ")
USER = USER << 6
CURSOR = SECRET & 0b11000000
print "USER:", BITFORMAT.format(USER)
print "STATE0:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
USER = USER << 4
CURSOR = SECRET & 0b00110000

print "USER:", BITFORMAT.format(USER)
print "STATE1:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
USER = USER << 2
CURSOR = SECRET & 0b00001100

print "USER:", BITFORMAT.format(USER)
print "STATE2:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")


USER = input("input: ")
USER = USER << 0
CURSOR = SECRET & 0b00000011

print "USER:", BITFORMAT.format(USER)
print "STATE3:", BITFORMAT.format(CURSOR), "\n"

if CURSOR != USER:
    sys.exit("\x1b[1;31;40mBUZZER ON\x1b[0m")

print "\x1b[1;32;40mLED ON\x1b[0m"
