m, a, b, c = map(int, input().split())
valid = max(a, b, c) <= m and a + b + c <= 2 * m
print('possible' if valid else 'impossible')
