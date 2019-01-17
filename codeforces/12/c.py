from collections import Counter

n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
c = Counter(input() for _ in range(m))
freqs = c.most_common()

x, y, p = 0, 0, 0
for _, v in freqs:
    x += v * a[p]
    p += 1

a.reverse()
p = 0
for _, v in freqs:
    y += v * a[p]
    p += 1

print(x, y)
