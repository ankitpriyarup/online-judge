def prev(h, m, s):
    while s <= 0:
        s += 60
        m -= 1
    while m < 0:
        h -= 1
        m += 60
    if h < 0:
        h += 12

    return (h, m, s - 1)

h, m, s = map(int, input().split())
delta = s + 60 * (m + 60 * h)
mod = 60 * 60 * 12

x = delta % mod
state = (12, 0, 0)
for _ in range(x):
    state = prev(*state)

print('{:02d}:{:02d}:{:02d}'.format(*state))
