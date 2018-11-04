n = int(input())
den = 1
ans = 0.0
for i in range(min(55, n + 1)):
    ans += 1.0 / den
    den *= (i + 1)

print(ans)
