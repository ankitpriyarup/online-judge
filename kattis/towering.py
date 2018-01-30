x = list(map(int, input().split()))
tgt = x[-2:]
x = x[:-2]
x.sort(reverse=True)

printed = False
s = sum(x)
for a in range(6):
    for b in range(a + 1, 6):
        for c in range(b + 1, 6):
            v = x[a] + x[b] + x[c]
            if v == tgt[0] and (s - v) == tgt[1]:
                if printed:
                    break

                printed = True
                res = []
                for i in range(6):
                    if i in (a, b, c):
                        res.append(x[i])
                for i in range(6):
                    if i not in (a, b, c):
                        res.append(x[i])

                print(' '.join(str(x) for x in res))
