l, m = map(int, input().split())
best_price = float('inf')
best = []
min_in_week = 10080
for _ in range(m):
    n, p, c, t, r = input().split(',')
    p, c, t, r = map(int, [p, c, t, r])

    den = t + r
    num = min_in_week * c * t
    if num >= den * l:
        if p < best_price:
            best = []
            best_price = p
        if p == best_price:
            best.append(n)

if best:
    print('\n'.join(best))
else:
    print('no such mower')
