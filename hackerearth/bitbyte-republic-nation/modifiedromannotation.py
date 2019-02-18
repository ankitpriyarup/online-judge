vals = []
p = 1
while len(vals) < 26:
    vals.append(p)
    vals.append(5 * p)
    p *= 10

# print(vals)
n = int(input())
p = 25
res = []
a = ord('A')
while n > 0:
    while vals[p] > n or p % 2 == 1:
        p -= 1
    k = n // vals[p]
    # print(n, p, vals[p], k)
    assert 1 <= k < 10
    if k == 9:
        res.append(chr(a + p))
        res.append(chr(a + p + 2))
    elif k == 4:
        res.append(chr(a + p))
        res.append(chr(a + p + 1))
    else:
        d = 0
        if k >= 5:
            res.append(chr(a + p + 1))
            d = 5
        for _ in range(k - d):
            res.append(chr(a + p))

    n -= k * vals[p]

print(''.join(res))
