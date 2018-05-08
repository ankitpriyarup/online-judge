from math import gcd
n = int(input())
k = n // 2
while gcd(n, k) > 1:
    k -= 1
print(k)
