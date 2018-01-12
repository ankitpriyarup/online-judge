from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

sys.setrecursionlimit(int(1e6))

def dfs(side, total, s):
    best = (0, 0)
    for i, p in enumerate(total):
        if i in s:
            continue

        a, b = p

        if a == side:
            s.add(i)
            l, ss = dfs(b, total, s)
            best = max(best, (l + 1, ss + a + b))
            s.remove(i)
        elif b == side:
            s.add(i)
            l, ss = dfs(a, total, s)
            best = max(best, (l + 1, ss + a + b))
            s.remove(i)

    return best

def main():
    ports = [tuple(map(int, line.strip().split('/'))) for line in sys.stdin]
    print(dfs(0, ports, set()))

main()
