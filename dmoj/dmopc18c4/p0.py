r, x, y = map(int, input().split())

mm, best = float('inf'), float('inf')

for _ in range(3):
    xi, yi, mi = map(int, input().split())
    dx = xi - x
    dy = yi - y
    if dx * dx + dy * dy < r * r:
        mm = min(mm, mi)
    best = min(best, mi)

if mm == best:
    print('What a beauty!')
else:
    print('Time to move my telescope!')
