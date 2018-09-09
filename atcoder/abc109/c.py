from functools import reduce
from math import gcd
n, x = map(int, input().split())
y = [abs(int(v) - x) for v in input().split()]
g = y[0] if len(y) == 1 else reduce(gcd, y)
print(g)
