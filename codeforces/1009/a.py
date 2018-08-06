n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
p = 0
ans = 0
for x in a:
    if p >= m:
        break
    if b[p] >= x:
        ans += 1
        p += 1
print(ans)
