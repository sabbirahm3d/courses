import matplotlib.pyplot as plt
from pandas import read_csv

file_path = 'lab_data.csv'

df = read_csv(file_path)


def plotIV(x, y, title, fig_name, ver_label):

    first_non_zero = list(df[x].iloc[df[y].nonzero()[0]])[0]

    fig, ax = plt.subplots(nrows=1, ncols=1)
    fig.suptitle(title, fontsize=20)
    plt.ylabel('Diode Current (mA)')
    plt.xlabel('Diode Voltage (V)')
    plt.plot(df[x], df[y], '-r', label='I-V curve')
    plt.axvline(x=first_non_zero, linestyle='--', label=ver_label)
    ax.legend(loc='upper center', shadow=True)
    fig.savefig(fig_name)


plotIV('Vd_1', 'Id_1', 'I-V Curve of Figure 1',
       'figure3.png', 'Turn-on voltage')
plotIV('Vd_2', 'Id_2', 'I-V Curve of Figure 2',
       'figure4.png', 'Breakdown voltage')
