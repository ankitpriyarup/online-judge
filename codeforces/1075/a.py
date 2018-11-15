n = int(input())
x, y = map(int, input().split())
x -= 1
y -= 1
d0 = max(x, y)
d1 = max(n - 1 - x, n - 1 - y)
if d0 <= d1:
    print('White')
else:
    print('Black')
