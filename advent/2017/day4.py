from collections import *
import itertools
import random
import sys

def main():
    ans = 0
    for line in sys.stdin:
        words = [''.join(sorted(x)) for x in line.strip().split()]
        if len(words) == len(set(words)):
            ans += 1

    print(ans)

main()
