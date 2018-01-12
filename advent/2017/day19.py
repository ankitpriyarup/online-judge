from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def safe(grid, nx, ny):
    return (0 <= nx < len(grid) and 0 <= ny < len(grid[nx]) and grid[nx][ny] != ' ')

def main():
    grid = [line for line in sys.stdin]
    print(grid)
    x = 0
    y = grid[0].index('|')
    d = 0
    moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    ans = []
    steps = 0
    while True:
        print(x, y)
        steps += 1
        if 'A' <= grid[x][y] <= 'Z':
            ans.append(grid[x][y])

        nx, ny = x + moves[d][0], y + moves[d][1]
        if safe(grid, nx, ny):
            x, y = nx, ny
            continue

        found = False
        for move in [moves[(d + 1) % 4], moves[(d + 3) % 4]]:
            nx, ny = x + move[0], y + move[1]
            if safe(grid, nx, ny):
                x, y = nx, ny
                d = moves.index(move)
                found = True
                break

        if not found:
            break

    print(''.join(ans))
    print(steps)

main()
