SECRET = 0b00011011

MASK = (1 << 2) - 1
# print bin(SECRET)
# print bin(SECRET - 0b00)
# print bin(SECRET ^ 0b00001011)

Char1 = SECRET & 0xFF
Char2 = SECRET >> 8
MyShort = (Char2 << 8) | Char1

print(bin(Char1))
print(bin(Char2))
print(bin(MyShort))
