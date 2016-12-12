from os import path

import matplotlib.pyplot as plt
from numpy import arange, pi, sin
from pandas import read_csv
import seaborn as sns

BASE_DIR = path.dirname(path.dirname(path.abspath(__file__)))
fig_path = path.join(BASE_DIR, 'statics/')

df = read_csv("final_output_pspice.csv")

sns.set_style(style='whitegrid')
fig, ax = plt.subplots(nrows=1, ncols=1)
Fs = 8000
f = 3.6
sample = len(df["t"])
x = arange(sample)
y = sin(2 * pi * f * x / Fs)


def final_gain():

    plt.plot(1000 * df["t"], 2763 * df["v"], 'r-',
             label=r"$Output\ voltage,\ v_{o}$")
    plt.plot(1000 * df["t"], 1000 * 0.001 * y, 'b-',
             label=r"$Input\ voltage,\ v_{i}$")

    plt.title("Final Circuit Gain", fontsize=20)
    plt.ylabel(r'$Voltage\ (mV)$')
    plt.xlabel(r'$Time\ (ms)$')


def audio_max():

    # plt.plot(1000 * df["t"], 5000 * df["v"], 'r-',
    #          label=r"$Output\ voltage,\ v_{o}$")
    plt.plot(1000 * df["t"], 0.001 * y, 'b-',
             label=r"$Input\ voltage,\ v_{i}$")
    plt.plot(1000 * df["t"], 2.4 * y, 'r-',
             label=r"$Input\ voltage,\ v_{i}$")

    plt.title("Final Circuit Gain", fontsize=20)
    plt.ylabel(r'$Voltage\ (mV)$')
    plt.xlabel(r'$Time\ (ms)$')


# final_gain()
audio_max()
lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)
fig.savefig(path.join(fig_path, 'audio_max.png'),
            bbox_extra_artists=(lgd,), bbox_inches='tight')
