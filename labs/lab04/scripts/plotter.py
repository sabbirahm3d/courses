from os.path import abspath, dirname
from os.path import join as path_join

import matplotlib.pyplot as plt
from pandas import read_csv
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def import_dataset(dataset):

    df = read_csv(path_join(BASE_DIR, 'data', dataset))

    return df


def plot_waves(v_bb, v_cc, v_ce, i_c, title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    plt.title(title, fontsize=20)
    plt.ylabel(r'$Collector\ Current,\ i_{C}\ (mA)$')
    plt.xlabel(r'$Collector-Emitter\ Voltage,\ V_{CE}\ (V)$')

    plt.plot(v_bb, v_cc, '-b', label='Input Voltage')
    plt.plot(v_ce, i_c, '-r', label=' Voltage')
    plt.plot(v_ce, i_c, 'og', label=' Voltage')

    plt.xlim(0, 10)
    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


if __name__ == '__main__':

    df = import_dataset('c.csv')

    if 'neg i_c' in list(df):
        df['i_c'] = -df['neg i_c']
        df.drop('neg i_c', axis=1, inplace=True)
        df.to_csv(path_join(BASE_DIR, 'data', 'c.csv'), index=False)

    # v_bb, v_cc, v_ce, i_c = list(df)
    # new_df = df[df['v_cc'] == 5]
    # print new_df.head()

    plot_waves(new_df[v_ce], new_df[i_c], df[v_ce], df[i_c],
               'Simulated BJT Characteristic Curve', 'test')

    # df = import_dataset('a.csv')
    # df['i_c'] = abs(df['v_cc'] - df['v_ce']) / 2200
    # df.drop('v_be', axis=1, inplace=True)

    # v_bb, v_cc, v_ce, i_c = list(df)

    # df1 = import_dataset('b.csv')
    # df1['i_c'] = df1['i_c'] / 1000
    # v_bb1, v_cc1, v_ce1, i_c1 = list(df1)

    # print df1.head()

    # plot_waves(df1[v_ce1], df1[i_c1], df[v_ce], df[i_c],
    #            'Simulated BJT Characteristic Curve', 'test2')
