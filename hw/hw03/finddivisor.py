from sys import argv

a, b, r = [int(i) for i in argv[1:]]

print(a, b, r)
max_it = max(a, b, r)

for n in xrange(max_it):
    for m in xrange(max_it):
        if (n * b - m * r == a):
            raise RuntimeError("m: {0} n: {1}".format(n, m))

print "None found"
