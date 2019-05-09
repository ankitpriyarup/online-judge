a = list(input().split())
n = len(a)
ls = [x for x in range(n) if a[x] == 'L']
rs = [x for x in range(n) if a[x] == 'R']
for x, y in zip(ls, rs):
    print(x + 1, y + 1)
