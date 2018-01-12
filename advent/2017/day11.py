from collections import *
from functools import reduce
import itertools
import random
import sys

def main():
    dx = [-1, -1, 0, 0, 1, 1]
    dy = [-1, 0, -1, 1, 0, 1]
    dirs = ["n", "ne", "nw", "se", "sw", "s"]

    words = input().split(",")
    x = 0
    y = 0
    ans = 0
    for d in words:
        i = dirs.index(d)
        x += dx[i]
        y += dy[i]
        ans = max(ans, max(x, y))

    print(ans)

main()
