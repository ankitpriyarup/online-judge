from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def find(uf, x):
    if uf[x] == x:
        return x
    uf[x] = find(uf, uf[x])
    return uf[x]

def merge(uf, x, y):
    xr = find(uf, x)
    yr = find(uf, y)
    if xr == yr:
        return 0
    uf[xr] = yr
    return 1

def conn(xs, ys):
    n = len(xs)
    uf = list(range(n))
    cc = n
    for i in range(n):
        for j in range(i + 1, n):
            dx = xs[i] - xs[j]
            dy = ys[i] - ys[j]
            if abs(dx) <= 3 and abs(dy) <= 3:
                cc -= merge(uf, i, j)

    return cc == 1

def main():
    lines = [line.strip() for line in sys.stdin]
    asteroids = []
    for line in lines:
        # x = int(line[10:16])
        # y = int(line[19:24])
        # vx = int(line[36:38])
        # vy = int(line[40:42])
        x, y, vx, vy = map(int, line.split())
        asteroids.append((x, y, vx, vy))

    for t in range(100000):
        xs = [x + t * vx for x, _, vx, _ in asteroids]
        ys = [y + t * vy for _, y, _, vy in asteroids]

        min_x = min(xs)
        max_x = max(xs)
        min_y = min(ys)
        max_y = max(ys)

        w = max_x - min_x + 1
        h = max_y - min_y + 1

        if not (w < 100 and h < 100):
            continue

        print(t, w, h)
        grid = [['.' for _ in range(w)] for _ in range(h)]

        for x, y in zip(xs, ys):
            grid[y - min_y][x - min_x] = '#'

        for row in grid:
            print(''.join(row))

        print('')


main()
