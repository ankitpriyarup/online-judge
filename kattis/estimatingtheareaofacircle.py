import sys
from math import pi
for line in sys.stdin:
    r, m, c = map(float, line.split())
    if r == 0:
        break
    area = pi * r * r
    frac = 4 * r * r * c / m
    print('{:.9f} {:.9f}'.format(area, frac))
