from math import gcd

T = int(input())
for tc in range(T):
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    s = 1
    while a[s - 1] == a[s]:
        s += 1
    b = [-1 for _ in range(l + 1)]
    b[s] = gcd(a[s - 1], a[s])
    for i in range(s - 1, -1, -1):
        b[i] = a[i] // b[i + 1]
    for i in range(s + 1, l + 1):
        b[i] = a[i - 1] // b[i - 1];
    c = list(b)
    c.sort()
    d = []
    for i, x in enumerate(c):
        if i == 0 or c[i - 1] != x:
            d.append(x)

    d_inv = {}
    for i, x in enumerate(d):
        d_inv[x] = i

    s = ''.join(chr(ord('A') + d_inv[x]) for x in b)
    print('Case #{}: {}'.format(tc + 1, s))
