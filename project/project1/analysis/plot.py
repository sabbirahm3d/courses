#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from ast import literal_eval

import numpy as np
import plotly.plotly as py
import plotly.graph_objs as go

from secret import API_KEY, USERNAME


def dist_scatter(x, cmul4_means, cmul3_means):

    cmul4 = go.Scatter(
        x=x,
        y=cmul4_means,
        opacity=0.4,
        marker={
            "color": "rgba(210, 50, 63, 1)"
        },
        name="cmul4",  # Style name/legend entry with html tags
        connectgaps=True
    )
    cmul3 = go.Scatter(
        x=x,
        y=cmul3_means,
        opacity=0.4,
        marker={
            "color": "rgba(48, 72, 115, 1)"
        },
        name="cmul4",  # Style name/legend entry with html tags
        connectgaps=True
    )

    # cmul3_32 = go.Scatter(
    #     x=x,
    #     y=all_means[1],
    #     marker={
    #         "color": ""
    #     },
    #     name="32 cmul3",  # Style name/legend entry with html tags
    #     opacity=0.8,
    # )

    data = [cmul4, cmul3]

    layout = go.Layout(
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


def diff_boxplot(file_names, diffs):

    data = []
    for file_name, diff in zip(x, diffs):
        data.append(go.Box(
            y=diff,
            name=x,
            boxpoints="all",
            jitter=0.2,
            whiskerwidth=0.2,
            line=dict(width=1),
            showlegend=False,
        ))

    layout = go.Layout(
        xaxis={
            "title": "Data Size",
        },
        yaxis={
            "title": "$(t_{cmul4()} - t_{cmul3()}) \ ms$",
        },
        font={"size": 20},
        height=900, width=1800
    )

    fig = go.Figure(data=data, layout=layout)

    return fig


if __name__ == "__main__":

    fig_dir = "report/figures/"

    times_files_32 = [
        "cmplx_numbers_32_008bit.txt",
        "cmplx_numbers_32_010bit.txt",
        "cmplx_numbers_32_020bit.txt",
        "cmplx_numbers_32_030bit.txt",
        "cmplx_numbers_32_040bit.txt",
        "cmplx_numbers_32_100bit.txt",
        "cmplx_numbers_32_200bit.txt",
    ]

    times_files_64 = [
        "cmplx_numbers_64_008bit.txt",
        "cmplx_numbers_64_010bit.txt",
        "cmplx_numbers_64_020bit.txt",
        "cmplx_numbers_64_030bit.txt",
        "cmplx_numbers_64_040bit.txt",
        "cmplx_numbers_64_100bit.txt",
        "cmplx_numbers_64_200bit.txt",
    ]

    # credentials for plot.ly API
    py.sign_in(username=USERNAME, api_key=API_KEY)

    for ix, times_files in enumerate((times_files_32, times_files_64)):

        file_names = [x.split("/")[-1][:-4] for x in times_files]
        means = []
        diffs = []

        for file in times_files:
            with open("timestats/" + file) as anaylsis_file:
                for _ in range(2):
                    means.append(float(next(anaylsis_file)[11:-4]))

                next(anaylsis_file)
                diffs.append(literal_eval(next(anaylsis_file)))

        def reject_outliers(data, m=10):
            d = np.abs(data - np.median(data))
            mdev = np.median(d)
            s = d / mdev if mdev else 0.
            return data[s < m]

        diffs = [reject_outliers(np.array(diff)) for diff in diffs]

        x = [x[17:-3] for x in file_names]

        fig = diff_boxplot(file_names, diffs)
        py.image.save_as(
            fig,
            filename=fig_dir + str(32 * (ix + 1)) + "diffs.png"
        )

        fig = dist_scatter(x, means[::2], means[1::2])
        py.image.save_as(
            fig,
            filename=fig_dir + str(32 * (ix + 1)) + "means.png"
        )
