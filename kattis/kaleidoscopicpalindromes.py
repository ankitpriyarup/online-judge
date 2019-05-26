from __future__ import print_function, division

def is_pal(x, j):
    a = []
    while x > 0:
        a.append(x % j)
        x //= j
    return a == a[::-1]

a, b, k = map(int, raw_input().split())
ans = 0
while a <= b and a < 2:
    ans += 1
    a += 1

if k <= 3:
    for x in xrange(a, b + 1):
        valid = all(is_pal(x, j) for j in xrange(2, k + 1))
        if valid:
            ans += 1

print(ans)
