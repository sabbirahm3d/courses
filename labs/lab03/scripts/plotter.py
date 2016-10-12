from os.path import abspath, dirname
from os.path import join as path_join

import matplotlib.pyplot as plt
from numpy import pi, sin
from pandas import read_csv
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def plotify(dataset, title, src, circuit, num, fig_name):

    data_points = import_dataset(dataset)
    x, y1, y2 = list(data_points)
    plot_waves(x=data_points[x], y1=data_points[y1], y2=data_points[y2],
               src=src, circuit=circuit, num=num,
               title=title, fig_name=fig_name)


def import_dataset(dataset):

    df = read_csv(path_join(BASE_DIR, 'data', dataset))

    # sanity from excess whitespace
    df = df.rename(columns=lambda col: col.replace(' ', '').lower())
    return df


def plot_theoretical(x, circuit, num):

    theoretical_in = 0
    theoretical_out = 0

    if circuit == 'clipper':
        amp = 6
        min_clipped = -(4 + 0.7)

        theoretical_out = theoretical_in = amp * sin(20000 * pi * x)

        if not num:
            max_clipped = 2 + 0.7
            theoretical_out = [
                max_clipped if val > max_clipped
                else val for val in theoretical_out]

        else:
            max_clipped = 4 + 0.7
            theoretical_out = [
                max_clipped if val > max_clipped
                else val for val in theoretical_out]

        theoretical_out = [
            min_clipped if val < min_clipped
            else val for val in theoretical_out]

    elif circuit == 'clamper':
        amp = 4
        v_b = 7.7 if not num else 4.5

        theoretical_in = amp * sin(20000 * pi * x)
        theoretical_out = amp * sin(20000 * pi * x) + v_b

    plt.plot(x, theoretical_in, '--k',
             label='Theoretical Input')
    plt.plot(x, theoretical_out, '--c',
             label='Theoretical Output')


def plot_waves(x, y1, y2, src, circuit, num, title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    plt.title(title, fontsize=20)
    plt.ylabel('Voltage (V)')
    plt.xlabel('Time (s)')

    if src == 'oscilloscope':

        plt.plot(x, y1, '-r', label='Input Voltage')
        plt.plot(x, y2, '-b', label='Output Voltage')

    elif src == 'theory':

        plot_theoretical(x, circuit, num)

    elif src == 'both':

        plt.plot(x, y1, '-r', label='Input Voltage')
        plt.plot(x, y2, '-b', label='Output Voltage')
        plot_theoretical(x, circuit, num)

    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)
    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


if __name__ == '__main__':

    plotify(dataset='a.csv', title='Clipper Circuit I',
            src='oscilloscope', circuit='clipper', num=0, fig_name='a_1')
    plotify(dataset='a.csv', title='Clipper Circuit I',
            src='theory', circuit='clipper', num=0, fig_name='a_2')
    plotify(dataset='a.csv', title='Clipper Circuit I',
            src='both', circuit='clipper', num=0, fig_name='a_3')

    plotify(dataset='b.csv', title='Clipper Circuit II',
            src='oscilloscope', circuit='clipper', num=1, fig_name='b_1')
    plotify(dataset='b.csv', title='Clipper Circuit II',
            src='theory', circuit='clipper', num=1, fig_name='b_2')
    plotify(dataset='b.csv', title='Clipper Circuit II',
            src='both', circuit='clipper', num=1, fig_name='b_3')

    plotify(dataset='c1.csv', title='Clamper Circuit I',
            src='oscilloscope', circuit='clamper', num=0, fig_name='c1_1')
    plotify(dataset='c1.csv', title='Clamper Circuit I',
            src='theory', circuit='clamper', num=0, fig_name='c1_2')
    plotify(dataset='c1.csv', title='Clamper Circuit I',
            src='both', circuit='clamper', num=0, fig_name='c1_3')

    plotify(dataset='c2.csv', title='Clamper Circuit II',
            src='oscilloscope', circuit='clamper', num=1, fig_name='c2_1')
    plotify(dataset='c2.csv', title='Clamper Circuit II',
            src='theory', circuit='clamper', num=1, fig_name='c2_2')
    plotify(dataset='c2.csv', title='Clamper Circuit II',
            src='both', circuit='clamper', num=1, fig_name='c2_3')
