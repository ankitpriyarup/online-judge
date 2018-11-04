n = int(input())
f = []
for _ in range(n):
    x, z = input().split()
    x = int(x)
    z = float(z)
    f.append((x, z))
f.sort()
ans = 0.0
for i in range(1, n):
    dx = abs(f[i][0] - f[i - 1][0])
    dz = abs(f[i][1] - f[i - 1][1])
    ans = max(ans, dz / dx)

print(ans)
