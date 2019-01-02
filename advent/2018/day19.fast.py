# x = 1003
x = 10551403
ans = 0
d = 1
while d * d <= x:
    if x % d == 0:
        ans += d
        ans += x // d
    d += 1
print(ans)
