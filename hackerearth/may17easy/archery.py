from math import gcd
from functools import reduce

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n = int(input())
    l = list(map(int, input().split()))
    ans = reduce(lcm, l)
    print(ans)

T = int(input())
for _ in range(T):
    main()
