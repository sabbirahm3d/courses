from collections import OrderedDict  # for sorting hashtables
from string import ascii_uppercase  # for iterating through the alphabet
from pprint import pprint

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


def kmap_seq():

    var = []
    terms = []

    for i in xrange(4):
        var.append(binary(i, 2))

    var[3], var[2] = var[2], var[3]

    for x in xrange(2):
        for i in xrange(len(var)):
            for j in xrange(len(var)):
                terms.append(str(x) + var[i] + var[j])

    return terms


def state_assignment():

    codes = {}

    for i in range(len(STATES)):
        codes[ascii_uppercase[i]] = kmap_seq()[i][1:]

    # print OrderedDict(sorted(codes.items()))
    return OrderedDict(sorted(codes.items()))


def binary(value, bits):

    binary_val = '0' * bits + str(bin(value)[2:])

    if len(binary_val) > bits:
        return binary_val[len(binary_val) - bits:]

    return binary_val


def printer(index=None, switch=None, output=None, display=''):

    flip_flop = {}
    codes = state_assignment()

    for i, j in states(switch).iteritems():
        # print int((str(str(switch) + codes[i])), 2)

        if index is not None:
            flip_flop[int((str(str(switch) + codes[i])), 2)] = codes[j]

        else:
            flip_flop[int((str(str(switch) + codes[i])), 2)] \
                = dispense(i, switch)[output]

            if display == 'state':
                print STATES[i], '->', STATES[j], str(dispense(i, switch))
            elif display == 'codes':
                print codes[i], '->', codes[j], str(dispense(i, switch))
            elif display == 'clear':
                print i, '->', j, str(dispense(i, switch))

    return flip_flop


def minterms(flip_flop, index, pin=''):

    minterms = []
    dont_cares = []

    for i, j in flip_flop.iteritems():
        if pin == 'j':
            if int(j[index]) and not int(binary(i, 5)[1:][index]):
                minterms.append(i)
            elif int(binary(i, 5)[1:][index]):
                dont_cares.append(i)
        elif pin == 'k':
            if not int(binary(i, 5)[1:][index]):
                dont_cares.append(i)
            elif int(binary(i, 5)[1:][index]) and not int(j[index]):
                minterms.append(i)
        else:
            if int(j):
                minterms.append(i)

    return minterms, dont_cares


def pair_terms(mins):

    min_pairs = []

    for i in mins:
        min_pairs.append((int(binary(i, 5)[:3], 2), int(binary(i, 5)[3:], 2)))

    return min_pairs


def dont_cares():

    codes = kmap_seq()

    return codes[(len(codes) / 2) - 4:(len(codes) / 2)] + codes[-4:]


def ic_factory():

    pins = ['J0', 'J0_D', 'K0', 'K0_D', 'J1', 'J1_D', 'K1', 'K1_D',
            'J2', 'J2_D', 'K2', 'K2_D', 'J3', 'J3_D', 'K3', 'K3_D']

    functions = {key: None for key in pins}

    print functions['J0']


ic_factory()

J0 = sorted(minterms(printer(index=0, switch=0), 0, 'j')[0] +
            minterms(printer(index=0, switch=1), 0, 'j')[0])

J0_D = sorted(minterms(printer(index=0, switch=0), 0, 'j')[1] +
              minterms(printer(index=0, switch=1), 0, 'j')[1])

K0 = sorted(minterms(printer(index=0, switch=0), 0, 'k')[0] +
            minterms(printer(index=0, switch=1), 0, 'k')[0])

K0_D = sorted(minterms(printer(index=0, switch=0), 0, 'k')[1] +
              minterms(printer(index=0, switch=1), 0, 'k')[1])

J1 = sorted(minterms(printer(index=1, switch=0), 1, 'j')[0] +
            minterms(printer(index=1, switch=1), 1, 'j')[0])

J1_D = sorted(minterms(printer(index=1, switch=0), 1, 'j')[1] +
              minterms(printer(index=1, switch=1), 1, 'j')[1])

K1 = sorted(minterms(printer(index=1, switch=0), 1, 'k')[0] +
            minterms(printer(index=1, switch=1), 1, 'k')[0])

K1_D = sorted(minterms(printer(index=1, switch=0), 1, 'k')[1] +
              minterms(printer(index=1, switch=1), 1, 'k')[1])

J2 = sorted(minterms(printer(index=2, switch=0), 0, 'j')[0] +
            minterms(printer(index=2, switch=1), 0, 'j')[0])

J2_D = sorted(minterms(printer(index=2, switch=0), 0, 'j')[1] +
              minterms(printer(index=2, switch=1), 0, 'j')[1])

K2 = sorted(minterms(printer(index=2, switch=0), 0, 'k')[0] +
            minterms(printer(index=2, switch=1), 0, 'k')[0])

K2_D = sorted(minterms(printer(index=2, switch=0), 0, 'k')[1] +
              minterms(printer(index=2, switch=1), 0, 'k')[1])

J3 = sorted(minterms(printer(index=3, switch=0), 1, 'j')[0] +
            minterms(printer(index=3, switch=1), 1, 'j')[0])

J3_D = sorted(minterms(printer(index=3, switch=0), 1, 'j')[1] +
              minterms(printer(index=3, switch=1), 1, 'j')[1])

K3 = sorted(minterms(printer(index=3, switch=0), 1, 'k')[0] +
            minterms(printer(index=3, switch=1), 1, 'k')[0])

K3_D = sorted(minterms(printer(index=3, switch=0), 1, 'k')[1] +
              minterms(printer(index=3, switch=1), 1, 'k')[1])

w = sorted(minterms(printer(switch=0, output=0), -1)[0] +
           minterms(printer(switch=1, output=0), -1)[0])

z = sorted(minterms(printer(switch=0, output=1), -1)[0] +
           minterms(printer(switch=1, output=1), -1)[0])

print "Minterms for J0:", J0
print "Don't cares for J0:", J0_D
print "Minterms for K0:", K0
print "Don't cares for K0:", K0_D
print "Minterms for J0:", J1
print "Don't cares for J0:", J1_D
print "Minterms for K0:", K1
print "Don't cares for K0:", K1_D
print "Minterms for J2:", J2
print "Don't cares for J2:", J2_D
print "Minterms for K2:", K2
print "Don't cares for K2:", K2_D
print "Minterms for J3:", J3
print "Don't cares for J3:", J3_D
print "Minterms for K3:", K3
print "Don't cares for K3:", K3_D
print "Minterms for w:", w
print "Minterms for z:", z
print "Default don't cares:", [int(i, 2) for i in dont_cares()]

# functions = {}

# functions['D0'] = pair_terms(D0)
# functions['D1'] = pair_terms(D1)
# functions['D2'] = pair_terms(D2)
# functions['D3'] = pair_terms(D3)
# functions['z'] = pair_terms(z)
# functions['w'] = pair_terms(w)

# functions = OrderedDict(sorted(functions.items()))

# for i, j in functions.iteritems():
#     print i, j

# yo = []

# for i in functions.values():
#     for j in i:
#         yo.append(j)


# decoders = [i[0] for i in yo]

# print (set(decoders))

all_minterms = J0 + K0 + J1 + K1 + J2 + K2 + J3 + K3 + w + z
all_dont_cares = [int(i, 2) for i in dont_cares()] + J0_D + K0_D + J1_D + \
    K1_D + J2_D + K2_D + J3_D + K3_D

print '\n', len(set(all_minterms)), 'different minterms'
print (list(set(all_minterms)))
print '\n', len(set(all_dont_cares)), 'different dont_cares'
print (list(set(all_dont_cares)))
