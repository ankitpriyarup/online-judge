#!/bin/python3

from collections import Counter

n = int(input())
a = list(map(int, input().split()))

c = Counter(a)
maxx = max(a)
minn = min(a)

if c[maxx] > 1 and c[minn] > 1:
    print(maxx - minn)
elif c[maxx] > 1:
    c[minn] -= 1
    print(maxx - min(c.elements()))
elif c[minn] > 1:
    c[maxx] -= 1
    print(max(c.elements()) - minn)
else:
    c[maxx] -= 1
    c[minn] -= 1
    print(min(maxx - min(c.elements()), max(c.elements()) - minn))
