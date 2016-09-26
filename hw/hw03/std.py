from math import sqrt

var = 0

e = 4.09

for i in xrange(1, 6):

    var += ((i - e)**2) * (i**2 / 55.0)

print var
print sqrt(var)
