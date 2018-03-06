n, k = map(int, input().split())
ans = 0
for _ in range(n):
    x = int(input())
    if x >= k:
        ans += 1
print(ans)
