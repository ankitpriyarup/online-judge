n = int(input())
a = list(map(int, input().split()))
x = 0
y = sum(a)
ans = y
for v in a:
    x += v
    y -= v
    ans = min(ans, abs(x - y))

print(ans)

