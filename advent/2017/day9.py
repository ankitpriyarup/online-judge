from collections import *
import itertools
import random
import sys

def main():
    s = input()
    score = 0
    in_garb = False
    ignore = False
    ans = 0
    ct = 0
    for c in s:
        if ignore:
            ignore = False
            continue

        if c == '!':
            ignore = True
            continue

        if in_garb and c == '>':
            in_garb = False
            continue
        elif in_garb:
            ct += 1
            continue

        if c == '<':
            in_garb = True
            continue

        if c == '{':
            score += 1
            ans += score
            continue
        elif c == '}':
            score -= 1
            continue

    print(ans)
    print(ct)


main()
