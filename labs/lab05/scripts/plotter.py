from os.path import abspath, dirname
from os.path import join as path_join

import matplotlib.pyplot as plt
from numpy import arange
import seaborn as sns

BASE_DIR = dirname(dirname(abspath(__file__)))
fig_path = path_join(BASE_DIR, 'figures/')


def plot_waves(title, fig_name):

    sns.set_style(style='whitegrid')
    fig, ax = plt.subplots(nrows=1, ncols=1)

    r_c = 2000
    r_e = 424.24
    v_ce = arange(0, 8, 0.01)
    i_c_dc = [1000 * (8 - i) / (r_c + r_e) for i in v_ce]
    i_c_ac_t = [1000 * ((8 - i) / (r_c)) for i in v_ce]
    i_c_ac = [1000 * (-0.00035 + (8 - i) / (r_c)) for i in v_ce]
    q_point = i_c_dc[list(v_ce).index(4)]

    plt.plot(v_ce, i_c_dc, '-r', label='DC Load line')
    plt.plot(v_ce, i_c_ac_t, '--b', label='Temporary AC Load line')
    plt.plot(v_ce, i_c_ac, '-b', label='AC Load line')

    plt.axvline(x=4, ymax=q_point / 4, linewidth=2, color='g', ls='dashed')
    plt.axhline(y=q_point, xmax=0.5, color='g', ls='dashed')
    ax.text(0, q_point + 0.05, str(round(q_point, 4)) + ' mA', fontsize=14)
    ax.annotate('Q-Point', xy=(4, q_point), xytext=(2.5, 1.2),
                arrowprops=dict(facecolor='black', shrink=0.05))

    plt.title(title, fontsize=20)
    plt.ylabel(r'$Collector\ Current,\ i_{C}\ (mA)$')
    plt.xlabel(r'$Collector-Emitter\ Voltage,\ V_{CE}\ (V)$')

    plt.ylim([0, 4])

    fig.savefig(fig_path + fig_name + '.png',
                bbox_extra_artists=(ax.legend(),),
                bbox_inches='tight')


if __name__ == '__main__':

    plot_waves('Load Lines of the Common Emitter Circuit', 'fig5')
