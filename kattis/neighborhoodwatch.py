n, k = map(int, input().split())
a = [int(input()) for _ in range(k)]
safe = [False for _ in range(n)]
for x in a:
    safe[x - 1] = True
last = n
ans = 0
for x in range(n - 1, -1, -1):
    if safe[x]:
        last = x
    if last == n:
        continue
    ans += n - x - (last - x)
print(ans)
