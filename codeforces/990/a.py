n, m, a, b = map(int, input().split())
extra = n % m
ans = min(b * extra, a * (m - extra))
print(ans)
