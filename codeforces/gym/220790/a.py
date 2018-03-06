n, k = map(int, input().split())
a = []
for _ in range(n):
    a.append(int(input()))


a.sort()
ans = 0
for i in range(k):
    ans += a[n - 1 - i]

print(ans)
