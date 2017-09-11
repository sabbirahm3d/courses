# because testing your code on Python before MATLAB is the cool thing to do

import matplotlib.pyplot as plt
from numpy import arange, convolve, zeros_like

t = arange(0, 5, 0.01)


def pulse(t, T):

    def unit(x):
        return int(x >= 0)

    return unit(t) - unit(t - T)


x = [pulse(i, 1) for i in t]
h = [pulse(i, 1) for i in t]

yhat = zeros_like(t)
n = int(t[-1])

for i in xrange(len(t)):
    for j in xrange(i + 1):
        yhat[i] += x[j] * h[i - j]


fig, ax = plt.subplots(nrows=1, ncols=1)
fig.suptitle('Iteration Convolution Test', fontsize=20)
plt.plot(yhat, '-r', label='I-V curve')
fig.savefig('iteration.png')

print min(convolve(x, h))

fig, ax = plt.subplots(nrows=1, ncols=1)
fig.suptitle('NumPy Convolution Test', fontsize=20)
plt.plot(convolve(x, h), '-r', label='I-V curve')
fig.savefig('numpy.png')
