n, k = map(int, input().split())
ans = float('inf')
for x in map(int, input().split()):
    if k % x == 0:
        ans = min(ans, k // x)

print(ans)
