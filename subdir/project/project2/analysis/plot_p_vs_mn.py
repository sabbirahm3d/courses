#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json

import plotly.plotly as py
import plotly.graph_objs as go

from secret import API_KEY, USERNAME


def core_scatter(data, xaxis, bpad=100,
                 ytitle="$\\text{Speedup } \\bigg(\\frac{T_1}{T_P}\\bigg)$"
                 ):

    plot_data = []

    for core in xaxis:
        plot_data.append(
            go.Scatter(
                x=data[core]["x"],
                y=data[core]["t1/tn"],
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
        },
        yaxis={
            "title": ytitle,
        },
        font={
            "size": 18
        },
        height=900, width=1600,
        margin={
            "b": bpad,
        },
        legend={"traceorder": "normal"}
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
                equal_cols.add(row["dims"])
            else:
                unequal_rows.append(row)
                unequal_cols.add(row["dims"])

    equal_cores = {
        core: {
            "x": [],
            "y": [],
        }
        for core in equal_cols
    }

    for row in equal_rows:
        for core in equal_cols:
            if row["dims"] == core:
                equal_cores[core]["x"].append(row["core"])
                equal_cores[core]["y"].append(row["time"])

    equal_keys = [i for i in equal_cores.keys()]
    equal_keys = sorted(equal_keys, key=lambda x: int(x.split("x")[0]))

    for k, v in equal_cores.items():
        t1 = v["y"][0]
        equal_cores[k]["t1/tn"] = [i / t1 for i in v["y"]]

    unequal_cores = {
        core: {
            "x": [],
            "y": [],
        }
        for core in unequal_cols
    }

    for row in unequal_rows:
        for core in unequal_cols:
            if row["dims"] == core:
                unequal_cores[core]["x"].append(row["core"])
                unequal_cores[core]["y"].append(row["time"])

    unequal_keys = [i for i in unequal_cores.keys()]
    unequal_keys = sorted(unequal_keys, key=lambda x: int(
        x.split("x")[0]) + int(x.split("x")[1]))

    for k, v in unequal_cores.items():
        t1 = v["y"][0]
        unequal_cores[k]["t1/tn"] = [i / t1 for i in v["y"]]

    # credentials for plot.ly API
    py.sign_in(username=USERNAME, api_key=API_KEY)

    fig = core_scatter(equal_cores, equal_keys)
    py.image.save_as(
        fig, filename=figure_dir + "equal_t1tpxp.png"
    )

    # fig = core_scatter(unequal_cores, unequal_keys, -100)
    # py.image.save_as(
    #     fig, filename=figure_dir + "unequal_t1tpxp.png"
    # )
