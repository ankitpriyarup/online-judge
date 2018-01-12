from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def rot(g):
    g = list(list(r) for r in g)
    n = len(g)
    assert(n == len(g[0]))
    out = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            out[i][j] = g[n - j - 1][i]

    return tuple(''.join(row) for row in out)

def flip(g):
    g = list(list(r) for r in g)
    n = len(g)
    assert(n == len(g[0]))
    out = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            out[i][j] = g[j][i]

    return tuple(''.join(row) for row in out)

def extract(grid, i, j, s):
    return tuple(grid[i + x][j:j+s] for x in range(s))

def place(mat, i, j, block):
    n = len(block)
    for x in range(n):
        for y in range(n):
            mat[i + x][j + y] = block[x][y]

def expand(rules, grid):
    n = len(grid)
    sz = 0
    if n % 2 == 0:
        sz = 3 * (n // 2)
    else:
        sz = 4 * (n // 3)
    out = [[None for _ in range(sz)] for _ in range(sz)]
    if n % 2 == 0:
        for i in range(0, n, 2):
            for j in range(0, n, 2):
                seed = extract(grid, i, j, 2)
                place(out, 3 * (i // 2), 3 * (j // 2), rules[seed])
    else:
        for i in range(0, n, 3):
            for j in range(0, n, 3):
                seed = extract(grid, i, j, 3)
                place(out, 4 * (i // 3), 4 * (j // 3), rules[seed])

    return tuple(''.join(row) for row in out)

def main():
    m = {}
    for line in sys.stdin:
        rule = line.strip().split(' => ')
        pred = tuple(rule[0].split('/'))
        suff = tuple(rule[1].split('/'))

        for _ in range(2):
            for _ in range(4):
                m[pred] = suff
                pred = rot(pred)

            pred = flip(pred)

    grid = ['.#.', '..#', '###']
    for _ in range(18):
        grid = expand(m, grid)

    ans = 0
    for row in grid:
        ans += sum(1 for c in row if c == '#')

    print(ans)

main()
