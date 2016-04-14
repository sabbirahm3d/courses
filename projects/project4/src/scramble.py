from random import shuffle
from sys import exit

list_of_words = []

try:
    with open('strings.txt', 'r') as input_file:
        for i in range(sum(1 for line in open('strings.txt', 'r'))):
            lines = str(input_file.readline())
            list_of_words.append(lines)

except IOError:
    exit(str(input_file) + ".txt does not exist.")

shuffle(list_of_words)

for i in list_of_words:
    print i.strip('\n')
