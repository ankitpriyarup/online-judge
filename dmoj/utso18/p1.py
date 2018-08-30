n, m = map(int, input().split())
print(max(n + m, n - m, m - n, n * m))
