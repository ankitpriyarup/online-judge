from math import sqrt

x, y, x1, y1, x2, y2 = map(int, input().split())
if x1 <= x <= x2:
    ans = min(abs(y1 - y), abs(y - y2))
elif y1 <= y <= y2:
    ans = min(abs(x1 - x), abs(x - x2))
else:
    corners = [(x1, y1), (x1, y2), (x2, y1), (x2, y2)]
    ans = float('inf')
    for xx, yy in corners:
        dx = xx - x
        dy = yy - y
        cur = sqrt(dx * dx + dy * dy)
        ans = min(ans, cur)

print('{:.3f}'.format(ans))
