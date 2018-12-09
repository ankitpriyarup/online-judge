from collections import *
import itertools
import random
import sys

def parse(line):
    _, _, rc, wh = line.split()
    r, c = map(int, rc[:-1].split(','))
    w, h = map(int, wh.split('x'))
    return (r, c, w, h)

def main():
    lines = [line.strip() for line in sys.stdin]
    lines = [parse(line) for line in lines]
    m = defaultdict(int)
    for r, c, w, h in lines:
        for i in range(w):
            for j in range(h):
                m[(r + i, c + j)] += 1
    # ans = sum(1 for _, v in m.items() if v > 1)
    idx = 0
    for r, c, w, h in lines:
        idx += 1
        solo = True
        for i in range(w):
            for j in range(h):
                solo = solo and m[(r + i, c + j)] == 1
        if solo:
            print(idx)
            break


main()
