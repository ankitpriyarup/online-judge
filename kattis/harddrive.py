from __future__ import print_function, division

n, c, b = map(int, raw_input().split())
broken = [int(x) - 1 for x in raw_input().split()]
out = ['0' for _ in range(n)]
start = 1
if c % 2 == 1:
    c -= 1
    out[0] = '1'
    start = 2

p = 0

while c > 0 and start < n:
    while p < b and broken[p] < start:
        p += 1
    # print(p, broken[p], start)
    if p < b and broken[p] == start:
        p += 1
        start += 1
        continue
    c -= 2
    out[start] = '1'
    start += 2

print(''.join(out))

