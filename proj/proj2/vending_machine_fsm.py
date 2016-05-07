#!/usr/bin/env python

"""vending_machine_fms.py

Script for generating minterms for a sequential circuit as described in
proj2.pdf"""

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

# special states
CHANGE = [5, 15]


def states(switch):
    """Maps current state to the next based on input

    Input: input from the switch, 0 or 1
    Output: a map containing the state transitions"""

    # to contain the state transitions
    state_table = {}

    # if switch == 0, input is 25 cents
    # if switch == 1, input is 10 cents
    coin = 10 if switch == 1 else 25

    for i, j in STATES.iteritems():

        if ((j + coin) % MAX) in STATES.values():
            # map current state to the next state if they are both in the table
            state_table[i] = \
                STATES.keys()[STATES.values().index((j + coin) % MAX)]

        elif ((j + coin) % MAX) in CHANGE:
            # map current state to the next state if it's a special state
            state_table[i] = \
                STATES.keys()[STATES.values().index((j + coin) % MAX - 5)]

    return state_table


def dispense(state, switch):
    """Determines outputs based on state transitions

    Input: state -> current state
           switch -> input from the switch, 0 or 1
    Output: a tuple of outputs, z0, z1"""

    coin = 10 if switch == 1 else 25

    # next state
    total = STATES[state] + coin

    if (total >= MAX):

        if (total - MAX) in CHANGE:
            # dispense voucher and change of 5 cents
            return 1, 1

        # dispense voucher only
        return 1, 0

    # no output
    return 0, 0


def kmap_seq():
    """Generates 5 bit minterms in a K-map sequence

    Input: none
    Output: a tuple of outputs, z0, z1"""

    var = []
    terms = []

    # 2 bit minterms
    for i in xrange(4):
        var.append(binary(i, 2))

    # swap 10 with 11 to make them adjacent
    var[3], var[2] = var[2], var[3]

    for x in xrange(2):
        for i in xrange(len(var)):
            for j in xrange(len(var)):
                terms.append(str(x) + var[i] + var[j])  # 5 bit minterms

    return terms


def dont_cares():
    """Generates list of unused states as don't cares

    Input: none
    Output: list of default don't cares"""

    # get the list of states assigned to coded minterms
    codes = kmap_seq()

    # take the last 4 minterms of each halves
    return codes[(len(codes) / 2) - 4:(len(codes) / 2)] + codes[-4:]


def state_assignment():
    """Assigns states to minterms

    Input: none
    Output: a map of states with their corresponding minterms"""

    codes = {}

    for i in xrange(len(STATES)):
        codes[ascii_uppercase[i]] = kmap_seq()[i][1:]

    return codes


def binary(value, bits):
    """Convert decimal to base 2 in number of bits inputted

    Input: value -> decimal value
           bits -> number of bits
    Output: base 2 of the decimal value"""

    binary_val = '0' * bits + str(bin(value)[2:])

    if len(binary_val) > bits:
        return binary_val[len(binary_val) - bits:]

    return binary_val


def code_transitions(index=None, switch=None, output=None, display=''):
    """Maps transitions and outputs with the next based on minterm codes

    Input: index -> index of the minterm codes corresponding to the flip flop
            output
           switch -> input from the switch, 0 or 1
           output -> index of the minterm codes corresponding to the output
           display -> option to print transitions
    Output: map of transitions in coded minterms"""

    flip_flop = {}
    codes = state_assignment()

    for i, j in states(switch).iteritems():

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
    """Generates minterms for functions

    Input: flip_flop -> map of transitions
           index -> index of the minterm codes corresponding to the flip flop
            output
           pin = corresponds to 'j' or 'k' in a JK flip flop
    Output: list of minterms and don't cares for the function"""

    minterms = []
    dont_cares = []

    for i, j in flip_flop.iteritems():

        if pin == 'j':
            # if Q == 0 and Q_next == 1
            if int(j[index]) and not int(binary(i, 5)[1:][index]):
                minterms.append(i)
            # if Q == 1
            elif int(binary(i, 5)[1:][index]):
                dont_cares.append(i)

        elif pin == 'k':
            # if Q == 1 and Q_next == 0
            if not int(binary(i, 5)[1:][index]):
                dont_cares.append(i)
            # if Q == 0
            elif int(binary(i, 5)[1:][index]) and not int(j[index]):
                minterms.append(i)

        else:
            # if Q_next == 1
            if int(j):
                minterms.append(i)

    return minterms, dont_cares


def ic_factory():
    """Generates minterms for all the ICs and outputs

    Input: none
    Output: maps minterms for the functions"""

    pins = ['J0', 'J0_D', 'K0', 'K0_D', 'J1', 'J1_D', 'K1', 'K1_D', 'J2',
            'J2_D', 'K2', 'K2_D', 'J3', 'J3_D', 'K3', 'K3_D', 'z0', 'z1']

    functions = {pin: [] for pin in pins}

    for bins in xrange(2):
        for bits in xrange(4):
            functions['J' + str(bits)].extend(sorted(
                minterms(
                    code_transitions(index=bits, switch=bins), bits, 'j')[0]
            ))
            functions['K' + str(bits)].extend(sorted(
                minterms(
                    code_transitions(index=bits, switch=bins), bits, 'k')[0]
            ))
            functions['J' + str(bits) + '_D'].extend(sorted(
                minterms(
                    code_transitions(index=bits, switch=bins), bits, 'j')[1]
            ))
            functions['K' + str(bits) + '_D'].extend(sorted(
                minterms(
                    code_transitions(index=bits, switch=bins), bits, 'k')[1]
            ))
        for outputs in xrange(2):
            functions['z' + str(outputs)].extend(sorted(
                minterms(code_transitions(switch=bins, output=outputs), -1)[0]
            ))

    # sorts map
    return OrderedDict(sorted(functions.items()))


if __name__ == '__main__':

    print __doc__, '\n'

    print "Default don't cares:", [int(i, 2) for i in dont_cares()]

    for i, j in ic_factory().iteritems():
        print i, j
