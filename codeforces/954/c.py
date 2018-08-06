def to_xy(v, y):
    v -= 1
    return (v // y, v % y)

def verify(a, y):
    pos = to_xy(a[0], y)
    for v in a[1:]:
        p2 = to_xy(v, y)
        d = sum(abs(pos[k] - p2[k]) for k in range(2))
        if d != 1:
            return False

        pos = p2

    return True

n = int(input())
a = list(map(int, input().split()))
opts = set()
poss = True
for i in range(1, n):
    d = abs(a[i] - a[i - 1])
    if d == 0:
        poss = False
    if d == 1:
        continue
    opts.add(abs(d))

if not poss or len(opts) >= 2:
    print('NO')
elif len(opts) == 0:
    print('YES')
    print('1 1000000000')
elif len(opts) == 1:
    y = list(opts)[0]
    if verify(a, y):
        print('YES')
        print('1000000000 ' + str(y))
    else:
        print('NO')

