e, f, c = map(int, input().split())
e += f
ans = 0
while e >= c:
    drank = e // c
    ans += drank
    e -= c * drank
    e += drank

print(ans)
