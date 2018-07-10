n, m, d = map(int, input().split())

# (n - 1) spots for beauty
# if enabled, m^(n - 2) sequences that have that spot

# (n - 1) * (pairs) * (n - 2)^m / 
# E(1) = 0
# E(2) = E(1) + P(i - 1, i)
# E(3) = E(2)

# (m - 1) * pairs / (n choose 2) 
pairs = n if d == 0 else 2 * (n - d)
num = (m - 1) * pairs
den = n * n
print('{:.15f}'.format(num / den))
