from collections import *
from functools import reduce
import itertools
import random
import sys

def main():
    g = [0 for _ in range(100)]
    for line in sys.stdin:
        a, b = map(int, line.strip().split(': '))
        g[a] = b

    for delay in range(100000000):
        poss = True
        for t in range(100):
            if g[t] == 0:
                continue

            pos = (delay + t) % (2 * g[t] - 2)
            if pos == 0:
                poss = False
                break

        if poss:
            print(delay)

main()
