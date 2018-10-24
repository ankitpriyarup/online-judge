n = int(input())
d = 0
a = (0, 0)
for _ in range(n):
    x, y = map(int, input().split())
    dd = x * x + y * y
    if dd > d:
        d = dd
        a = (x, y)
print(*a)
