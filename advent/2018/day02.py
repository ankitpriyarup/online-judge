from collections import *
import itertools
import random
import sys

def main():
    names = []
    for line in sys.stdin:
        names.append(line.strip())

    n = len(names)
    for i in range(n):
        for j in range(i + 1, n):
            eq = sum(a == b for a, b in zip(names[i], names[j]))
            if eq == len(names[i]) - 1:
                out = [a for a, b in zip(names[i], names[j]) if a == b]
                print(''.join(out))


main()
