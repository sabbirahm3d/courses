from os import path

import matplotlib.pyplot as plt
from numpy import arange, pi, sin
from pandas import read_csv
import seaborn as sns

BASE_DIR = path.dirname(path.dirname(path.abspath(__file__)))
fig_path = path.join(BASE_DIR, 'figures/')

df = read_csv("final_output_pspice.csv")

sns.set_style(style='whitegrid')
fig, ax = plt.subplots(nrows=1, ncols=1)

plt.plot(1000 * df["t"], 2763 * df["v"], 'r-',
         label=r"$Output\ voltage,\ v_{o}$")
Fs = 8000
f = 3.6
sample = len(df["t"])
x = arange(sample)
y = sin(2 * pi * f * x / Fs)
plt.plot(1000 * df["t"], 1000 * 0.001 * y, 'b-',
         label=r"$Input\ voltage,\ v_{i}$")

plt.title("Final Circuit Gain", fontsize=20)
plt.ylabel(r'$Voltage\ (mV)$')
plt.xlabel(r'$Time\ (ms)$')
lgd = ax.legend(loc=1)
fig.savefig('final_gain.png', bbox_extra_artists=(lgd,))
