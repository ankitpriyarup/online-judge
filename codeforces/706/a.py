from math import sqrt

x, y = map(int, input().split())
n = int(input())
best = float("inf")
for _ in range(n):
    a, b, v = map(int, input().split())
    a, b = abs(a - x), abs(b - y)
    dist = sqrt(0.0 + a * a + b * b)
    best = min(best, dist / v)

print(best)
