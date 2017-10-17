#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import argv
from ast import literal_eval

import plotly.plotly as py
import plotly.graph_objs as go

from secret import API_KEY, USERNAME


def diff_scatter(x, y, title):

    trace = go.Scatter(
        x=x,
        y=y,
        mode="markers",
    )
    data = [trace]
    layout = go.Layout(title=title, height=900, width=2000)
    fig = go.Figure(data=data, layout=layout)

    return fig


if __name__ == "__main__":

    if len(argv) > 1:

        file_name = argv[-1].split('/')[-1].replace(".txt", ".png")
        data = []
        with open(argv[-1]) as f:
            for _ in range(6):
                next(f)  # quick way to skip the lines
            for j in f:
                data.append(j)

        data = literal_eval(data[1])

        # credentials for plot.ly API
        py.sign_in(username=USERNAME, api_key=API_KEY)

        fig = diff_scatter(list(range(1, 201)), data, file_name[:-4])
        py.image.save_as(fig, filename=file_name)
