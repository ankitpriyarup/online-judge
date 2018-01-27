from collections import Counter, defaultdict, deque
import itertools
import math
import sys

def single(a, b):
    if a =='0':
        return b
    if b == '0':
        return a

    return str(int(a) % int(b))

def do_hash(tx, s):
    out = ''.join(single(c, s[i % len(s)]) for i, c in enumerate(tx))
    return out

def main():
    tx, n, s = input().split()
    tx = int(tx)
    n = int(n)
    goal = '0' * n

    gap = 0
    while not do_hash(str(tx + gap), s).startswith(goal):
        gap += 1

    print(gap)

if __name__ == '__main__':
    main()
