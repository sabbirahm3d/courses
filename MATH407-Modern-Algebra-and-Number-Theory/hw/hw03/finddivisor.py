from sys import argv

a, b, r = [int(i) for i in argv[1:]]
max_it = max(a, b, r)


def find_divisor():
    for n in xrange(max_it):
        for m in xrange(max_it):
            if (n * b - m * r == a):
                return "{n} \cdot {b} - {m} \cdot {r}".format(
                    n=n, b=b, m=m, r=r
                )

    return "None found"


print find_divisor()
