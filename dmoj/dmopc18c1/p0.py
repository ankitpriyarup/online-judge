x = [int(input()) for _ in range(3)]
y = x[:]
y.sort()
print('Good job!'  if x == y else 'Try again!')
