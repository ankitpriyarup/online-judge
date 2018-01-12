from collections import *
from functools import reduce
import itertools
import random
import sys

a_fac = 16807
b_fac = 48271
mod = 2147483647
mask = (1 << 16) - 1

def make_gen(start, fac, div):
    x = fac * start % mod
    while True:
        if x % div == 0:
            yield x

        x = x * fac % mod

def main():
    a = make_gen(873, a_fac, 4)
    b = make_gen(583, b_fac, 8)
    ans = 0
    for _ in range(5 * int(1e6)):
        x = next(a)
        y = next(b)
        if (x & mask) == (y & mask):
            ans += 1
    print(ans)

main()
