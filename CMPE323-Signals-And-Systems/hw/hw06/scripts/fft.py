from numpy import arange, around, cos, pi, sin, fft
import numpy as np
import matplotlib.pyplot as plt
f1 = 1
f2 = 3
dt = 0.125
t = arange(0, 1, dt)

x = [4 * cos(2 * pi * f1 * i) - 3 * sin(2 * pi * f2 * i + pi / 4) for i in t]

fft_x = list(fft.fft(x))
# print [str(around(i, decimals=3)) for i in x]


def FFT_vectorized(x):
    """A vectorized, non-recursive version of the Cooley-Tukey FFT"""
    x = np.asarray(x, dtype=float)
    N = len(x)

    if N % 2:
        raise ValueError("size of x must be a power of 2")

    # Perform an O[N^2] DFT on all length-N_min sub-problems at once
    n = np.arange(N)
    k = n[:, None]
    M = np.exp(-2j * np.pi * n * k / N)
    X = np.dot(M, x.reshape((N, -1)))

    # build-up each level of the recursive calculation all at once
    while X.shape[0] < N:
        X_even = X[:, :X.shape[1] / 2]
        X_odd = X[:, X.shape[1] / 2:]
        factor = np.exp(-1j * np.pi * np.arange(X.shape[0]) /
                        X.shape[0])[:, None]
        X = np.vstack([X_even + factor * X_odd,
                       X_even - factor * X_odd])

    return X.ravel()


new_x = FFT_vectorized(x)


def bit_reverse(n):
    return int('{:03b}'.format(n)[::-1], 2)


x = [x[bit_reverse(i)] for i in range(len(x))]


print "Shuffled input:", [float(around(i, decimals=3)) for i in x]
print "FFT(x):", [complex(str(around(i, decimals=3))) for i in new_x]


def plot_in_out(y, fig_name):

    fig, ax = plt.subplots(nrows=1, ncols=1)
    fig.suptitle('Input/Output Voltages', fontsize=20)
    plt.ylabel('Output Voltage (V)')
    plt.xlabel('Input Voltage (V)')
    plt.stem(range(8), y, '-b')
    plt.xlim([-1, 9])
    fig.savefig(fig_name)


# plot_in_out(np.absolute(new_x), 'test.png')
# plot_in_out(np.angle(new_x), 'test2.png')
