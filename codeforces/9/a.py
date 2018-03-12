from math import gcd
a, b = map(int, input().split())
num = (6 - max(a, b) + 1)
den = 6
g = gcd(num, den)
print('{}/{}'.format(num // g, den // g))
