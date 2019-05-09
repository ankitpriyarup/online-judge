a, b, t = map(int, input().split())
ans = 0
for v in range(a, t + 1, a):
    ans += b

print(ans)
