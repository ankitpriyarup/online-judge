from collections import *
from functools import reduce
import itertools
import random
import sys

def to_hex(c):
    out = hex(c)[2:]
    print(c, out, len(out))
    if len(out) == 1:
        return '0' + out
    else:
        return out

def main():
    # x = list(map(int, input().split(',')))
    x = [ord(c) for c in input().strip()]
    a = list(range(256))
    # a = list(range(5))
    add = list(map(int, '17, 31, 73, 47, 23'.split(', ')))
    x += add
    print(x)

    p = 0
    s = 0
    for _ in range(64):
        for y in x:
            b = a[p:] + a[:p]
            b = list(reversed(b[:y])) + b[y:]
            a = b[-p:] + b[:-p]
            p = p + y + s
            p %= len(a)
            s += 1

    out = []
    for i in range(0, 256, 16):
        block = a[i:i + 16]
        val = reduce(lambda x, y: x ^ y, block)
        out.append(to_hex(val))

    ans = (''.join(out))
    print(len(ans))
    print(ans)

main()
