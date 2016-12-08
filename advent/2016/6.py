from collections import Counter
import hashlib

def main():
    fin = open('6.in', 'r')

    counters = [Counter() for _ in range(8)]
    for line in fin:
        line = line.strip()
        for i, c in enumerate(line):
            counters[i][c] += 1

    for c in counters:
        print(c.most_common()[-1])



main()
