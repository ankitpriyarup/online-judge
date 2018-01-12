from collections import *
import itertools
import random
import sys

def follow(a):
    best_i = 0
    n = len(a)
    for i in range(n):
        if a[i] > a[best_i]:
            best_i = i
    b = list(a)
    x = a[best_i]
    b[best_i] = 0
    for i in range(x):
        b[(best_i + i + 1) % n] += 1

    return tuple(b)

def main():
    a = tuple(map(int, input().split()))
    s = set()
    steps = 0
    ct = 0
    while ct < 2:
        if a in s:
            print(steps)
            ct += 1
            s = set()
        s.add(a)
        steps += 1
        a = follow(a)

    print(steps)

# OFF BY ONE ERRORS!!!
main()
