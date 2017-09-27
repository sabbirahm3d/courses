import sys

BITFORMAT = "{:08b}"
SECRET = 0b11100100
JOYSTICK = 0b00000000

u = 0b00000000
d = 0b00000001
l = 0b00000010
r = 0b00000011

print "SECRET:", BITFORMAT.format(SECRET)
print "JOYSTICK:", BITFORMAT.format(JOYSTICK), "\n"

JOYSTICK = JOYSTICK + input("input: ")
CURSOR = SECRET >> 6
print "JOYSTICK:", BITFORMAT.format(JOYSTICK)
print "STATE0:", BITFORMAT.format(CURSOR)

if CURSOR != JOYSTICK:
    sys.exit("wrong")


JOYSTICK = JOYSTICK << 2
JOYSTICK = JOYSTICK + input("input: ")
CURSOR = SECRET >> 4

print "\nJOYSTICK:", BITFORMAT.format(JOYSTICK)
print "STATE1:", BITFORMAT.format(CURSOR)

if CURSOR != JOYSTICK:
    sys.exit("wrong")


JOYSTICK = JOYSTICK << 2
JOYSTICK = JOYSTICK + input("input: ")
CURSOR = SECRET >> 2

print "\nJOYSTICK:", BITFORMAT.format(JOYSTICK)
print "STATE2:", BITFORMAT.format(CURSOR)

if CURSOR != JOYSTICK:
    sys.exit("wrong")


JOYSTICK = JOYSTICK << 2
JOYSTICK = JOYSTICK + input("input: ")
CURSOR = SECRET

print "\nJOYSTICK:", BITFORMAT.format(JOYSTICK)
print "STATE3:", BITFORMAT.format(CURSOR)

if CURSOR != JOYSTICK:
    sys.exit("wrong")
