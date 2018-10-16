n, T = map(int, input().split())
ans = 1003
for _ in range(n):
    c, t = map(int, input().split())
    if t <= T:
        ans = min(ans, c)

print('TLE' if ans == 1003 else ans)
