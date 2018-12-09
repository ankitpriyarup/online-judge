from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def gen_list(after, start):
    out = [start]
    cur = after[start]
    while cur != start:
        out.append(cur)
        cur = after[cur]

    return out

def main():
    players = 465
    last = 7194000
    scores = [0 for _ in range(players)]

    before = {}
    after = {}
    before[0] = 0
    after[0] = 0

    cur = 0

    for x in range(1, last + 1):
        if x % 23 == 0:
            player = x % players
            scores[player] += x
            for _ in range(7):
                cur = before[cur]

            scores[player] += cur
            before[after[cur]] = before[cur]
            after[before[cur]] = after[cur]
            cur = after[cur]
        else:
            cur = after[cur]
            before[x] = cur
            after[x] = after[cur]
            after[before[x]] = x
            before[after[x]] = x

            cur = x

            # out = gen_list(after, 0)
            # print(' '.join(str(x) for x in out))

    print(max(scores))

main()
