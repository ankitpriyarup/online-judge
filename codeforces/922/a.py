x, y = map(int, input().split())
a, b = 0, 1
first = y - 1
a += first
b += first
if a <= x and ((a == x) or (a > 0 and (x - a) % 2 == 0)):
    print('Yes')
else:
    print('No')
