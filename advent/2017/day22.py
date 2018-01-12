from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def main():
    grid = [line.strip() for line in sys.stdin]
    state = defaultdict(int)

    for i, row in enumerate(grid):
        for j, cell in enumerate(row):
            if cell == '#':
                state[(i, j)] = 2

    n = len(grid)
    x, y = n // 2, n // 2
    d = 0
    moves = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    total, inf = 0, 0
    while total < 10000000:
        if state[(x, y)] == 2:
            d = (d + 1) % 4
        elif state[(x, y)] == 3:
            d = (d + 2) % 4
        elif state[(x, y)] == 0:
            d = (d + 3) % 4

        state[(x, y)] = (state[(x, y)] + 1) % 4
        if state[(x, y)] == 2:
            inf += 1

        total += 1
        x, y = x + moves[d][0], y + moves[d][1]

    print(inf, total)

main()
