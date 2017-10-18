#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from ast import literal_eval
from glob import glob

import plotly.plotly as py
import plotly.graph_objs as go

from secret import API_KEY, USERNAME


def dist_scatter(x, cmul4_line, cmul3_line):

    cmul4 = go.Scatter(
        x=x,
        y=cmul4_line,
        name="cmul4()",  # Style name/legend entry with html tags
        connectgaps=True
    )
    cmul3 = go.Scatter(
        x=x,
        y=cmul3_line,
        name="cmul3()",
    )

    data = [cmul4, cmul3]

    # fig = dict(data=data)

    layout = go.Layout(
        title="Mean Runtimes",
        xaxis={
            "title": "Data Size",
        },
        yaxis={
            "title": "ms",
        },
        font={"size": 18},
        height=900, width=1600
    )

    fig = go.Figure(data=data, layout=layout)

    return fig

    # py.iplot(fig, filename="simple-connectgaps")


def diff_boxplot(file_names, diffs):

    data = []
    for file_name, diff in zip(file_names, diffs):
        data.append(go.Box(
            y=diff,
            name=file_name[14:],
            boxpoints="all",
            jitter=0.2,
            whiskerwidth=0.2,
            line=dict(width=1),
            showlegend=False,
        ))

    layout = go.Layout(
        title="Distribution of Differences in The Multiplication Methods",
        xaxis={
            "title": "Data Size",
        },
        yaxis={
            "title": "$(t_{cmul4()} - t_{cmul3()}) \ ms$",
        },
        font={"size": 18},
        height=900, width=1600
    )

    fig = go.Figure(data=data, layout=layout)

    return fig


if __name__ == "__main__":

    times_dir = "times/*bit.txt"
    fig_dir = "report/figures/"

    times_files = [
        "cmplx_numbers_32_8bit.txt",
        "cmplx_numbers_34_8bit.txt",
        "cmplx_numbers_32_10bit.txt",
        "cmplx_numbers_25_20bit.txt",
        "cmplx_numbers_25_30bit.txt",
        "cmplx_numbers_25_40bit.txt",
        "cmplx_numbers_20_100bit.txt",
        "cmplx_numbers_20_200bit.txt",
    ]
    file_names = [x.split("/")[-1][:-4] for x in times_files]
    means = []
    medians = []
    std_devs = []
    diffs = []

    for file in times_files:
        with open("times/" + file) as anaylsis_file:
            for _ in range(2):
                means.append(float(next(anaylsis_file)[11:-4]))
            for _ in range(2):
                medians.append(float(next(anaylsis_file)[11:-4]))
            for _ in range(2):
                std_devs.append(float(next(anaylsis_file)[11:-4]))

            next(anaylsis_file)
            diffs.append(literal_eval(next(anaylsis_file)))

    # credentials for plot.ly API
    py.sign_in(username=USERNAME, api_key=API_KEY)

    fig = diff_boxplot(file_names, diffs)
    py.image.save_as(fig, filename=fig_dir + "diffs.png")

    fig = dist_scatter([x[14:] for x in file_names], means[::2], means[1::2])
    py.image.save_as(fig, filename=fig_dir + "means.png")
