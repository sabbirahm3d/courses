from collections import OrderedDict
from string import ascii_uppercase

STATES = {
    'A': 0,
    'B': 10,
    'C': 20,
    'D': 25,
    'E': 30,
    'F': 35,
    'G': 40,
    'H': 45,
    'I': 50,
    'J': 55,
    'K': 60,
    'L': 65,
    'M': 70
}

MAX = 70

def states(x):

    coins = {}

    coin = 10 if x == 1 else 25

    print "x =", x, "\n-----------"

    for i, j in STATES.iteritems():

        if ((j + coin) % MAX) in STATES.values():
            coins[i] = STATES.keys()[STATES.values().index((j + coin) % MAX)]

        if (j + coin) % MAX == 5:
            coins[i] = 'M'

        elif (j + coin) % MAX == 15:
            coins[i] = 'B'

    coins = OrderedDict(sorted(coins.items()))

    return coins


def dispense(state, x):

    coin = 10 if x == 1 else 25

    total = STATES[state] + coin

    if (total >= MAX):

        if ((total - MAX == 5) or (total - MAX == 15)):
            return 1, 1

        return 1, 0

    return 0, 0


def state_assignment():

    codes = {}

    for i in range(13):
        codes[ascii_uppercase[i]] = ('000' + str(bin(i)[2:]))
        if len(codes[ascii_uppercase[i]]) > 4:
            codes[ascii_uppercase[i]] = \
                ('000' + str(bin(i)[2:]))[len(codes[ascii_uppercase[i]])-4:]


    return OrderedDict(sorted(codes.items()))


def printer(value, x):

    flip_flop = {}
    codes = state_assignment()

    for i, j in states(x).iteritems():
        print codes[i], '->', codes[j], str(dispense(i, x))
        flip_flop[int((str(x) + str(codes[i])), 2)] = codes[j][value]

    print "\n"

    return flip_flop


def minterms(IC, flip_flop):

    minterms = []

    for i, j in flip_flop.iteritems():
        if int(j):
            minterms.append(i)

    return minterms


D0 = sorted(minterms('D0', printer(0, 0)) + minterms('D0', printer(0, 1)))
D1 = sorted(minterms('D1', printer(1, 0)) + minterms('D1', printer(1, 1)))
D2 = sorted(minterms('D2', printer(2, 0)) + minterms('D2', printer(2, 1)))
D3 = sorted(minterms('D3', printer(3, 0)) + minterms('D3', printer(3, 1)))

print "Minterms for D0", D0
print "Minterms for D1", D1
print "Minterms for D2", D2
print "Minterms for D3", D3
