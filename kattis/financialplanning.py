n, m = map(int, input().split())
c = [0] * n
p = [0] * n
for i in range(n):
    c[i], p[i] = map(int, input().split())

lo = 0
hi = int(1e10)
while lo + 1 < hi:
    mid = (lo + hi) // 2
    profit = 0
    for x, y in zip(c, p):
        if profit >= m:
            break
        profit += max(0, mid * x - y)
    if profit >= m:
        hi = mid
    else:
        lo = mid

print(hi)
