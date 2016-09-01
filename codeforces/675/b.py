n, a, b, c, d = map(int, input().split())

"""
xay
bmc
wdz
"""

ans = 0
for x in range(1, n + 1):
    y = x + b - c
    z = y + a - d
    w = z + c - b
    #print(x, y, z, w)
    if 1 <= y <= n and 1 <= z <= n and 1 <= w <= n:
        ans += 1

print(ans * n)
