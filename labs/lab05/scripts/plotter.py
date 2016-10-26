from os.path import abspath, dirname
from os.path import join as path_join

import matplotlib.pyplot as plt
from numpy import arange
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def plot_waves(title, fig_name):

    sns.set_style(style='darkgrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    r_c = 2000
    r_e = 424.24
    v_ce = arange(0, 8, 0.01)
    i_c_dc = [(8 - i) / (r_c + r_e) for i in v_ce]
    i_c_dc = [(8 - i) / (r_c + r_e) for i in v_ce]

    plt.plot(v_ce, i_c_dc, label=r'$Load\ line$')

    plt.title(title, fontsize=20)
    plt.ylabel(r'$Collector\ Current,\ i_{C}\ (A)$')
    plt.xlabel(r'$Collector-Emitter\ Voltage,\ V_{CE}\ (V)$')

    # plt.xlim(0, 10)
    lgd = ax.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(lgd,),
                bbox_inches='tight')


if __name__ == '__main__':

    plot_waves('test', 'test')
