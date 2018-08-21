from math import gcd

n, k = map(int, input().split())

g = gcd(n, k)
group_sz = n // g
ans = k * g * (group_sz - 1) + (k - 1) * (g - 1)
print(ans)
