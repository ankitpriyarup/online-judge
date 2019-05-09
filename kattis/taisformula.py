n = int(input())
points = []
for _ in range(n):
    t, v = input().split()
    t = int(t)
    v = float(v)
    points.append((t, v))

ans = 0
for p0, p1 in zip(points, points[1:]):
    dt = p1[0] - p0[0]
    area = dt * (p1[1] + p0[1]) / 2.0
    ans += area

print('{:.10f}'.format(ans / 1000.0))
