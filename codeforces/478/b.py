n, m = map(int, input().split())
hi = (n - (m - 1)) * (n - (m - 1) - 1) // 2
sz = n // m
extra = n % m
lo = (extra * (sz + 1) * sz) // 2 + ((m - extra) * sz * (sz - 1)) // 2
print(lo, hi)
