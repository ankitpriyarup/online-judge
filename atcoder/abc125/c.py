from fractions import gcd

n = int(raw_input())
a = list(map(int, raw_input().split()))
p = list(a)
s = list(a)
for i in range(1, n):
    p[i] = gcd(p[i - 1], p[i])
for i in range(n - 2, -1, -1):
    s[i] = gcd(s[i], s[i + 1])

ans = max(p[-2], s[1])
if n > 2:
    ans = max(ans, max(gcd(p[i - 1], s[i + 1]) for i in range(1, n - 1)))

print(ans)
