#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import path

from parselog import LogParser

from pprint import pprint


BASE_PATH = path.abspath(__file__)


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
                print "Found sequence with hamming distance above threshold provided (>{0})".format(self.thresh)
                print seq


if __name__ == '__main__':

    ids = IntrusionDetectionSystem(prog_name="sample_train.log", window_size=3)
    ids.train()
    ids.analyze("sample.log")
