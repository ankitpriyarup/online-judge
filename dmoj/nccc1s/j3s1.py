from math import sqrt
k, p, x = map(int, input().split())

def f(m):
    return m * x + k * p / m

# minimize (m^2x + kp)/m
# (2m^2x - m^2x - kp) = 0
# m^2x = kp

ans = sqrt(k * p / x)
res = float('inf')
for i in range(-10, 10):
    m = max(1, int(ans + i))
    res = min(res, f(m))

print('%.3f' % res)
