from os.path import abspath, dirname
from os.path import join as path_join

from pandas import read_csv
import matplotlib.pyplot as plt
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def plotify(dataset, title, fig_name):

    data_points = import_dataset(dataset)
    x, y1, y2 = list(data_points)
    plot_waves(x=data_points[x],
               y1=data_points[y1], y2=data_points[y2],
               title=title, fig_name=fig_name)


def import_dataset(dataset):

    df = read_csv(path_join(BASE_DIR, 'data', dataset))

    # sanity from excess whitespace
    df = df.rename(columns=lambda col: col.replace(' ', '').lower())
    return df


def plot_waves(x, y1, y2, title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)
    fig.suptitle(title, fontsize=20)

    plt.ylabel('Voltage (V)')
    plt.xlabel('Time (s)')
    plt.plot(x, y1, '-r', label='Input Voltage')
    plt.plot(x, y2, '-b', label='Output Voltage')

    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


if __name__ == '__main__':

    plotify('a.csv', 'Clipper Circuit I', 'a_')
    plotify('b.csv', 'Clipper Circuit II', 'b_')
    plotify('c1.csv', 'Clamper Circuit I', 'c1_')
    plotify('c2.csv', 'Clamper Circuit II', 'c2_')
