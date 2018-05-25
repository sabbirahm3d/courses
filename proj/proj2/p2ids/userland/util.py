#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json


def read_data(file_path, arr=False):

    with open(file_path) as file_obj:
        if arr:
            return dict(json.load(file_obj))
        return json.load(file_obj)


def write_data(file_path, data):

    with open(file_path, "w") as file_obj:
        json.dump(data, file_obj)
