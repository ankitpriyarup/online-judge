a, b = map(int, input().split())
v = (a + b) // 2
if abs(a - v) == abs(b - v):
    print(v)
else:
    print('IMPOSSIBLE')
