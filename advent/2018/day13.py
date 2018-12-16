from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def move(grid, cart):
    x, y, facing, turns = cart
    new_x, new_y = x + moves[facing][0], y + moves[facing][1]
    if grid[new_x][new_y] == '/':
        facing = 3 - facing
    elif grid[new_x][new_y] == '\\':
        facing ^= 1
    elif grid[new_x][new_y] == '+':
        if turns % 3 == 0:
            # left turn
            facing = (facing + 1) % 4
        elif turns % 3 == 2:
            # right turn
            facing = (facing + 3) % 4

        turns += 1
    else:
        assert(grid[new_x][new_y] in '-|')

    return (new_x, new_y, facing, turns)

def main():
    grid = [list(line[:-1]) for line in sys.stdin]
    n = len(grid)
    m = len(grid[0])

    print(n, m)

    # row, col, facing, num_turns
    carts = []
    symbs = 'v>^<'
    for i in range(n):
        for j in range(m):
            print(i, j, grid[i][j])
            if grid[i][j] in symbs:
                carts.append((i, j, symbs.index(grid[i][j]), 0))
                grid[i][j] = '-'

    print(carts)
    while True:
        carts.sort()
        skip = [False for _ in carts]

        new_carts = []
        new_skip = []
        for i, cart in enumerate(carts):
            if skip[i]:
                continue

            old_x, old_y, _, _ = cart

            new_carts.append(move(grid, cart))
            new_skip.append(False)
            x, y, _, _ = new_carts[-1]
            for j in range(i + 1, len(carts)):
                if skip[j]:
                    continue
                ox, oy, _, _ = carts[j]
                if (x, y) == (ox, oy):
                    skip[j] = True
                    new_skip[-1] = True

            for j in range(len(new_carts) - 1):
                if new_skip[j]:
                    continue
                nx, ny, _, _ = new_carts[j]
                if (x, y) == (nx, ny):
                    new_skip[j] = True
                    new_skip[-1] = True

        carts = []
        for i, cart in enumerate(new_carts):
            if not new_skip[i]:
                carts.append(cart)
        if len(carts) == 1:
            print(carts)
            break
        """
        for i, row in enumerate(grid):
            row = list(row)
            for x, y, f, _ in carts:
                if x == i:
                    row[y] = symbs[f]

            print(''.join(row))
        print()
        """

main()
