from os.path import abspath, dirname
from os.path import join as path_join

import matplotlib.pyplot as plt
from numpy import arange, linspace
from pandas import read_csv
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def import_dataset(dataset):

    df = read_csv(path_join(BASE_DIR, 'data', dataset))

    return df


def plot_waves(df, title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    color = iter(plt.cm.rainbow(linspace(0, 1, 7)))

    for i in arange(0, 3.5, 0.5):
        new_df = df[df['v_bb'] == i]
        i_b = str(round(i / 220000, 8))
        plt.plot(new_df['v_ce'], new_df['i_c'],
                 c=next(color),
                 label=r'$i_b = {}\ A$'.format(i_b))

    plt.title(title, fontsize=20)
    plt.ylabel(r'$Collector\ Current,\ i_{C}\ (mA)$')
    plt.xlabel(r'$Collector-Emitter\ Voltage,\ V_{CE}\ (V)$')
    plt.xlim(0, 10)
    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


def plot_part_c():

    df = import_dataset('c.csv')

    if 'neg i_c' in list(df):
        df['i_c'] = -df['neg i_c']
        df.drop('neg i_c', axis=1, inplace=True)
        df.to_csv(path_join(BASE_DIR, 'data', 'c.csv'), index=False)

    plot_waves(df, 'Simulated BJT Characteristic Curve', 'test')


if __name__ == '__main__':

    plot_part_c()

    df = import_dataset('a.csv')

    df['i_c'] = abs(df['v_cc'] - df['v_ce']) / 2200
    df.drop('v_be', axis=1, inplace=True)
    print df.tail()
    plot_waves(df, 'Simulated BJT Characteristic Curve', 'test1')

    df1 = import_dataset('b.csv')
    df1['i_c'] = df1['i_c'] / 1000
    # v_bb1, v_cc1, v_ce1, i_c1 = list(df1)

    # print df1.head()

    # plot_waves(df1[v_ce1], df1[i_c1], df[v_ce], df[i_c],
    #            'Simulated BJT Characteristic Curve', 'test2')
