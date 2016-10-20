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


def plot_waves(df, load_line_df, title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    color = iter(plt.cm.rainbow(linspace(0, 1, 7)))

    for i in arange(0, 3.5, 0.5):
        new_df = df[df['v_bb'] == i]
        i_b = str(round(i / 220000, 8))
        plt.plot(new_df['v_ce'], new_df['i_c'],
                 c=next(color),
                 label=r'$i_b = {}\ A$'.format(i_b))

    plt.plot(load_line_df[load_line_df['v_cc'] == 10]['v_ce'],
             load_line_df[load_line_df['v_cc'] == 10]['i_c'],
             label=r'$Load\ line$')

    plt.title(title, fontsize=20)
    plt.ylabel(r'$Collector\ Current,\ i_{C}\ (A)$')
    plt.xlabel(r'$Collector-Emitter\ Voltage,\ V_{CE}\ (V)$')

    plt.fill_between(df[df['v_bb'] == 3.0]['v_ce'],
                     df[df['v_bb'] == 3.0]['i_c'],
                     0, facecolor='yellow', alpha=0.5)
    plt.fill_between(df[df['v_cc'] == 10]['v_ce'],
                     df[df['v_cc'] == 10]['i_c'],
                     0, facecolor='yellow', alpha=0.5)
    plt.fill_between(df['v_cc'],
                     0, -0.001, facecolor='blue', alpha=0.5)

    plt.text(4, 0.0008, 'Forward active', fontsize=15)
    plt.text(4, -0.0005, 'Cutoff', fontsize=15)
    plt.text(0, 0.0045, 'Saturation', fontsize=15)

    plt.xlim(0, 10)
    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


def plot_part_a():

    df = import_dataset('a.csv')

    df['i_c'] = abs(df['v_cc'] - df['v_ce']) / 2200
    df.drop('v_be', axis=1, inplace=True)

    load_line_df = import_dataset('b.csv')
    load_line_df['i_c'] = load_line_df['i_c'] / 1000

    plot_waves(df, load_line_df, 'BJT Characteristic Curve', 'fig2')


def plot_part_c():

    df = import_dataset('c.csv')

    if 'neg i_c' in list(df):
        df['i_c'] = -df['neg i_c']
        df.drop('neg i_c', axis=1, inplace=True)
        df.to_csv(path_join(BASE_DIR, 'data', 'c.csv'), index=False)

    plot_waves(df, df, 'Simulated BJT Characteristic Curve', 'fig3')


if __name__ == '__main__':

    # plot_part_c()
    plot_part_a()
