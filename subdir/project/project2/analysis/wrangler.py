#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json

if __name__ == "__main__":

    data = []

    with open("data.txt") as data_file:
        row = {"core": 0, "dims": "", "time": 0, "equal": False}
        running_mean = 0
        for line_num, line in enumerate(data_file):

            if not line_num:
                split_line = line[:-1].split()
                row["core"], row["dims"], row["equal"] = \
                    int(split_line[1]), split_line[3] + "x" + \
                    split_line[5], split_line[3] == split_line[5]

            elif line_num % 6:
                running_mean += float(line[:-1])

            elif not line_num % 6:

                row["time"] = running_mean / 5.0
                running_mean = 0
                data.append(row)
                row = {"core": 0, "dims": "", "time": 0, "equal": False}
                split_line = line[:-1].split()
                row["core"], row["dims"], row["equal"] = \
                    int(split_line[1]), split_line[3] + "x" + \
                    split_line[5], split_line[3] == split_line[5]

        row["time"] = running_mean / 5.0
        data.append(row)

    with open("data.json", "w") as output_file:
        json.dump(data, output_file)
