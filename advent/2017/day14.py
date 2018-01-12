from collections import *
from functools import reduce
import itertools
import random
import sys

def to_bin(c):
    out = bin(c)[2:]

    while len(out) < 8:
        out = '0' + out

    return out

def knot_hash(key):
    x = [ord(c) for c in key.strip()]
    add = list(map(int, '17, 31, 73, 47, 23'.split(', ')))
    x += add
    a = list(range(256))
    p = 0
    s = 0
    for _ in range(64):
        for y in x:
            b = a[p:] + a[:p]
            b = list(reversed(b[:y])) + b[y:]
            a = b[-p:] + b[:-p]
            p = p + y + s
            p %= len(a)
            s += 1

    out = []
    for i in range(0, 256, 16):
        block = a[i:i + 16]
        val = reduce(lambda x, y: x ^ y, block)
        out.append(to_bin(val))

    ans = ''.join(out)
    return ans

def main():
    s = input()
    ans = 0
    grid = []
    for r in range(128):
        key = s + '-' + str(r)
        ret = knot_hash(key)

        grid.append(ret)

    vis = set()
    moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    ans = 0
    for i in range(128):
        for j in range(128):
            if grid[i][j] == '1' and (i, j) not in vis:
                ans += 1
                vis.add((i, j))
                q = [(i, j)]
                while q:
                    x, y = q.pop()
                    for dx, dy in moves:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < 128 and 0 <= ny < 128 and grid[nx][ny] == '1' and (nx, ny) not in vis:
                            vis.add((nx, ny))
                            q.append((nx, ny))

    print(ans)

main()
