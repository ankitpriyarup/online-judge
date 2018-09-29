n, s = map(int, input().split())
ans = -1
for _ in range(n):
    x, y = map(int, input().split())
    if x <= s and y == 0:
        ans = max(ans, 0)
    if x < s and y > 0:
        ans = max(ans, 100 - y)

print(ans)
