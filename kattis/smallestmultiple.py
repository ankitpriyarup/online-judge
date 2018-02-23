from functools import reduce
from math import gcd
import sys

def lcm(a, b):
    return a // gcd(a, b) * b

def main():
    for line in sys.stdin:
        a = [int(x) for x in line.strip().split()]
        r = reduce(lcm, a)
        print(r)

main()
