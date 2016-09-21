from os.path import abspath, dirname
from os.path import join as path_join
from sys import maxint

import matplotlib.pyplot as plt
from numpy import arange, flatnonzero
from pandas import read_csv

BASE_DIR = dirname(dirname(abspath(__file__)))

file_path = path_join(BASE_DIR, 'lab_data.csv')
fig_path = path_join(BASE_DIR, 'figures/')

df = read_csv(file_path)


def plot_data_IV(x, y, title, fig_name, ver_label):

    first_non_zero = list(df[x].iloc[df[y].nonzero()[0]])[0]

    fig, ax = plt.subplots(nrows=1, ncols=1)
    fig.suptitle(title, fontsize=20)
    plt.ylabel('Diode Current (mA)')
    plt.xlabel('Diode Voltage (V)')
    plt.plot(df[x], df[y], '-r', label='I-V curve')
    plt.axvline(x=first_non_zero, linestyle='--', label=ver_label)
    ax.legend(loc='upper center', shadow=True)
    fig.savefig(fig_path + fig_name)


def plot_ideal_IV(title, fig_name, piecewise=False):

    x = y = 0

    fig, ax = plt.subplots(nrows=1, ncols=1)
    fig.suptitle(title, fontsize=20)
    plt.ylabel('Diode Current (mA)')
    plt.xlabel('Diode Voltage (V)')

    if piecewise:
        CUTOFF_VOLTAGE = 1.2  # datasheet of 1N4732
        x = arange(-10.0, 10.0, 0.01)
        x[len(x) / 2 + 1] = 0.0
        print flatnonzero(x == 0.0)[0], len(x) / 2 + 1, x[len(x) / 2 + 1]
        y = [0.0] * (len(x) / 2 + 1)
        print y
        y = y + [float(1.0 / 8 * (i - CUTOFF_VOLTAGE))
                 for i in x[flatnonzero(x == 0.0)[0]:]]
        # y.append(maxint)
        print len(y), len(x)

    else:
        x = arange(-10.0, 0, 0.01)
        y = [0] * len(x)
        y[-1] = maxint

    plt.plot(x, sorted(y), '-r', label='I-V curve')
    ax.set_xlim([-10, 10])
    ax.legend(loc='upper center', shadow=True)
    fig.savefig(fig_path + fig_name)


if __name__ == '__main__':

    # plot_data_IV('Vd_1', 'Id_1', 'I-V Curve of Figure 1',
    #              'figure3.png', 'Turn-on voltage')
    # plot_data_IV('Vd_2', 'Id_2', 'I-V Curve of Figure 2',
    #              'figure4.png', 'Breakdown voltage')

    # plot_ideal_IV('Ideal Diode Model', 'test_fig.png')
    plot_ideal_IV('Ideal Diode Model', 'test_fig1.png', True)
