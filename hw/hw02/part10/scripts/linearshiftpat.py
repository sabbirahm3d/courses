#!/usr/bin/env python
# -*- coding: utf-8 -*-


if __name__ == "__main__":

    DUMPFILEPATH = "scripts/linear_shift_reg_dump.txt"
    BITS = 16
    MAXNUM = 2**BITS - 1  # maximum decimal integer with 16 bits
    DATA = []
    EXPECTDDATA = [bin(num)[2:].zfill(BITS) for num in xrange(1, MAXNUM)]

    missing_count = 0
    repeat_count = 0
    with open(DUMPFILEPATH) as dump_file:
        print "Dump file loaded..."
        print "Iterating through", MAXNUM, "terms to check for repetitions..."
        for line_num, line_str in enumerate(dump_file.readlines()):
            DATA.append(line_str[:-1])  # truncate the newline
            # if count(line) > 2 AND the line # is under 2 cycles
            if DATA.count(line_str[:-1]) > 2 and line_num < (MAXNUM * 2 - 2):
                print line_str[:-1], "is a term that repeated in a cycle"
                repeat_count += 1

    print "Checking for missing terms..."

    # convert the file data list to a set for faster membership checking
    DATA = set(DATA)

    # loop through the binary representation of every number from 1 to 2^n -1
    # and check if they have been created in the LFSR
    while len(EXPECTDDATA):
        if EXPECTDDATA[0] not in DATA:
            print EXPECTDDATA[0], "was not found in the expected terms"
            missing_count += 1
        else:
            # shrink the list to shorten the loop
            EXPECTDDATA = EXPECTDDATA[1:]

    print missing_count, "term(s) out of", MAXNUM, "are missing"
    print repeat_count, "term(s) were repeated in a single cycle"
