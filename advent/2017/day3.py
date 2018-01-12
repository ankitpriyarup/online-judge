from collections import *
import itertools
import random
import sys

# Y I K E S

def get_sum(s, x, y):
    ret = 0
    for dx in range(-1, 2):
        for dy in range(-1, 2):
            if (dx, dy) == (0, 0):
                continue
            if (x + dx, y + dy) in s:
                ret += s[(x + dx, y + dy)]

    return ret

def main():
    n = int(input())
    sz = 1
    while sz * sz < n:
        sz += 1

    # evens are up left, odds are down right
    x, y = 1, 0
    v = 2
    s = {(0, 0): 1}
    cur = 1
    while cur < n:
        vals = v * v - (v - 1) * (v - 1)
        if v % 2 == 0:
            for i in range(vals // 2):
                s[(x, y)] = cur
                y -= 1
                cur = get_sum(s, x, y)
                print(x, y, cur)

            for i in range(1 + vals // 2):
                s[(x, y)] = cur
                x -= 1
                cur = get_sum(s, x, y)
                print(x, y, cur)
        else:
            for i in range(vals // 2):
                s[(x, y)] = cur
                y += 1
                cur = get_sum(s, x, y)
                print(x, y, cur)
            for i in range(1 + vals // 2):
                s[(x, y)] = cur
                x += 1
                cur = get_sum(s, x, y)
                print(x, y, cur)

        v += 1

main()
