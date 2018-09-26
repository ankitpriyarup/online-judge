n, x = map(int, input().split())
p = 1
ans = 0
for _ in range(n):
    l, r = map(int, input().split())
    while p + x <= l:
        p += x
    ans += (r - p + 1)
    p = r + 1

print(ans)
