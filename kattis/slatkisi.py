n, k = map(int, input().split())
p = 1
for _ in range(k):
    p *= 10
rem = n % p
if 2 * rem >= p:
    n += p - rem
else:
    n -= rem
print(n)
