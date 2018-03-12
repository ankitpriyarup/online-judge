from math import sqrt

n, vb, vs = map(int, input().split())
a = list(map(int, input().split()))
x, y = map(int, input().split())

EPS = 1e-10
ans = float('inf')
bi = 1
olddist = float('inf')
for i in range(1, n):
    t1 = a[i] / vb

    dx = a[i] - x
    dist = sqrt(dx * dx + y * y)

    t2 = dist / vs

    # a[i] / vb + sqrt((a[i] - x) * (a[i] - x) + y * y) / vs
    # a[i] / vb + sqrt(a[i]^2 - 2a[i]x + x^2 + y^2) / vs

    # print(i, t1, t2, t1 + t2)
    if t1 + t2 + EPS < ans or abs(t1 + t2 - ans) < EPS and dist < olddist:
        ans = t1 + t2
        bi = i
        olddist = dist

print(bi + 1)
