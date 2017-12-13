#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
from math import log10

import plotly.plotly as py
import plotly.graph_objs as go

from secret import API_KEY, USERNAME


def core_scatter(data, tickangle=0, bpad=100):

    plot_data = []
    cores = [1, 2, 4, 8, 16]

    for core in cores:
        plot_data.append(
            go.Scatter(
                x=data[core]["x"],
                y=data[core]["y"],
                mode="lines+markers",
                marker={
                    "size": 10,
                },
                name=core,
                connectgaps=True
            )
        )

    layout = go.Layout(
        xaxis={
            "title":
            "$\\text{Sequence Lengths } (\\text{m} \\times \\text{n})$",
            "tickangle": tickangle,
        },
        yaxis={
            "title": "$\\text{Log of Mean Time } (log_\\text{10}(\\text{s}))$",
        },
        font={
            "size": 18
        },
        height=900, width=1600,
        margin={
            "b": bpad,
        }
    )

    fig = go.Figure(data=plot_data, layout=layout)

    return fig


if __name__ == "__main__":

    data = []
    equal_rows = []
    equal_cols = set()
    unequal_rows = []
    unequal_cols = set()
    figure_dir = "../report/figures/"

    with open("data.json") as data_file:
        data = json.load(data_file)
        for row in data:
            if row["equal"]:
                equal_rows.append(row)
                equal_cols.add(row["core"])
            else:
                unequal_rows.append(row)
                unequal_cols.add(row["core"])

    equal_cores = {
        core: {
            "x": [],
            "y": [],
        }
        for core in equal_cols
    }

    for row in equal_rows:
        for core in equal_cols:
            if row["core"] == core:
                equal_cores[core]["x"].append(row["dims"])
                equal_cores[core]["y"].append(log10(row["time"]))

    unequal_cores = {
        core: {
            "x": [],
            "y": [],
        }
        for core in unequal_cols
    }

    for row in unequal_rows:
        for core in unequal_cols:
            if row["core"] == core:
                unequal_cores[core]["x"].append(row["dims"])
                unequal_cores[core]["y"].append(log10(row["time"]))

    # credentials for plot.ly API
    py.sign_in(username=USERNAME, api_key=API_KEY)

    fig = core_scatter(equal_cores)
    py.image.save_as(
        fig, filename=figure_dir + "equal.png"
    )

    fig = core_scatter(unequal_cores, 90, 225)
    py.image.save_as(
        fig, filename=figure_dir + "unequal.png"
    )
