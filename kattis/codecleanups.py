n = int(input())
a = list(map(int, input().split()))
cur = 0
delta = 0
p = 0
ans = 0
for x in range(1, 566):
    if p < n and a[p] == x:
        delta += 1
        p += 1
    if cur + delta >= 20:
        cur = 0
        delta = 0
        ans += 1
    cur += delta
print(ans)
