from collections import OrderedDict  # for sorting hashtables
from string import ascii_uppercase  # for iterating through the alphabet

# the states of the sequence
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
    'L': 65
}

# overflow
MAX = 70

# special circumstances
CHANGE = [5, 15]


def states(switch):
    """Maps current state to the next based on input
    """

    state_table = {}

    # if switch == 0, input is 25 cents
    # if switch == 1, input is 10 cents
    coin = 10 if switch == 1 else 25

    # print "switch =", switch, "\n-----------"
    for i, j in STATES.iteritems():

        if ((j + coin) % MAX) in STATES.values():
            state_table[i] = \
                STATES.keys()[STATES.values().index((j + coin) % MAX)]

        elif (j + coin) % MAX in CHANGE:
            state_table[i] = \
                STATES.keys()[STATES.values().index((j + coin) % MAX - 5)]

    return OrderedDict(sorted(state_table.items()))


def dispense(state, switch):

    coin = 10 if switch == 1 else 25

    total = STATES[state] + coin

    if (total >= MAX):

        if (total - MAX) in CHANGE:
            return 1, 1

        return 1, 0

    return 0, 0


def state_assignment():

    codes = {}

    for i in range(len(STATES)):
        codes[ascii_uppercase[i]] = binary(i, 4)

    return OrderedDict(sorted(codes.items()))


def binary(value, bits):

    binary_val = '0000' + str(bin(value)[2:])

    if len(binary_val) > bits:
        return binary_val[len(binary_val) - bits:]

    return binary_val


def printer(value=None, switch=None, output=None, display=''):

    flip_flop = {}
    codes = state_assignment()

    if value is not None:

        for i, j in states(switch).iteritems():
            flip_flop[int((str(switch) + str(codes[i])), 2)] = codes[j][value]
            if display == 'state':
                print STATES[i], '->', STATES[j], str(dispense(i, switch))
            elif display == 'codes':
                print codes[i], '->', codes[j], str(dispense(i, switch))

    else:

        for i, j in states(switch).iteritems():
            flip_flop[int((str(switch) + str(codes[i])), 2)] \
                = dispense(i, switch)[output]
            if display == 'state':
                print STATES[i], '->', STATES[j], str(dispense(i, switch))
            elif display == 'codes':
                print codes[i], '->', codes[j], str(dispense(i, switch))

    return flip_flop


def minterms(flip_flop):

    minterms = []

    for i, j in flip_flop.iteritems():
        if int(j):
            minterms.append(i)

    return minterms


def pair_terms(mins):

    min_pairs = []

    for i in mins:
        min_pairs.append((int(binary(i, 5)[:3], 2), int(binary(i, 5)[3:], 2)))

    return min_pairs


D0 = sorted(minterms(printer(value=0, switch=0)) +
            minterms(printer(value=0, switch=1)))

D1 = sorted(minterms(printer(value=1, switch=0)) +
            minterms(printer(value=1, switch=1)))

D2 = sorted(minterms(printer(value=2, switch=0)) +
            minterms(printer(value=2, switch=1)))

D3 = sorted(minterms(printer(value=3, switch=0)) +
            minterms(printer(value=3, switch=1)))

z = sorted(minterms(printer(switch=0, output=0)) +
           minterms(printer(switch=1, output=0)))

w = sorted(minterms(printer(switch=0, output=1)) +
           minterms(printer(switch=1, output=1)))

print "Minterms for D0:", D0
print "Minterms for D1:", D1
print "Minterms for D2:", D2
print "Minterms for D3:", D3
print "Minterms for z:", z
print "Minterms for w:", w, "\n"

functions = {}

functions['D0'] = pair_terms(D0)
functions['D1'] = pair_terms(D1)
functions['D2'] = pair_terms(D2)
functions['D3'] = pair_terms(D3)
functions['z'] = pair_terms(z)
functions['w'] = pair_terms(w)

functions = OrderedDict(sorted(functions.items()))

for i, j in functions.iteritems():
    print i, j

# yo = []

# for i in functions.values():
#     for j in i:
#         yo.append(j)


# decoders = [i[0] for i in yo]

# print (set(decoders))

all_minterms = D0 + D1 + D2 + D3 + z + w

print '\n', len(set(all_minterms)), 'different minterms'
print (list(set(all_minterms)))
