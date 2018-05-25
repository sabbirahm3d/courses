#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse
from os import path
from subprocess import call

from config import LOG_PATH, LOGGER_PATH
from parselog import LogParser


class IntrusionDetectionSystem(object):

    def __init__(self, prog_name, window_size, thresh=2):

        self.prog_name = prog_name
        self.window_size = window_size
        self.thresh = thresh
        self.ids = LogParser(self.prog_name)

    def train(self):

        self.ids.set_healthy_seq(window_size=self.window_size)

    def analyze(self, log_file):

        vec = self.ids.vectorize(
            prog_name=log_file, window_size=self.window_size)

        for seq in vec:
            if seq["hamming_dist"] >= self.thresh:
                print ("Found sequence with hamming distance above threshold"
                       " provided (>{0})".format(self.thresh))
                print seq


if __name__ == '__main__':

    parser = argparse.ArgumentParser(
        description=("Intrusion Detection System: Execute this script "
                     "with the programs you would like to trace"),
        add_help=False
    )

    parser.add_argument("-h", "--help", action="help",
                        default=argparse.SUPPRESS,
                        help="| Show this help message and exit")

    parser.add_argument("--progs", "-p", action='append', metavar="CMD",
                        help="| List of programs", required=True)

    parser.add_argument("--log", "-l", default=LOG_PATH, metavar="PATH",
                        help="| Path to the logger executable")

    parser.add_argument("--window", "-k", default=5, metavar="N",
                        type=int, help="| Window size of sequences")

    parser.add_argument("--thresh", "-t", default=3, metavar="N", type=int,
                        help=("| Minimum threshold for hamming distances"
                              " to alarm the user"))

    # parse arguments to pass into function
    args = parser.parse_args()
    if (path.isfile(LOGGER_PATH)):
        for prog in args.progs:
            log_file_name = args.log + prog.split()[0] + ".log"
            call([LOGGER_PATH, log_file_name, prog])
            ids = IntrusionDetectionSystem(
                prog_name=log_file_name, window_size=args.window,
                thresh=args.thresh
            )
            ids.train()
            ids.analyze(log_file_name)

    else:
        print "Logger executable not compiled"
