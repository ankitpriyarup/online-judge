from collections import *
import itertools
import random
import sys

def solve1(s):
    ans = 0
    n = len(s)
    for i in range(n):
        if s[i] == s[(i + 1) % n]:
            ans += ord(s[i]) - ord('0')

    return ans

def solve2(s):
    ans = 0
    n = len(s)
    half = n // 2
    for i in range(n):
        if s[i] == s[(i + half) % n]:
            ans += ord(s[i]) - ord('0')

    return ans

def main():
    s = input()
    print(solve1(s))
    print(solve2(s))

main()
