a, b = map(int, input().split())
print('Yes' if any(a * b * c % 2 == 1 for c in range(1, 4)) else 'No')
