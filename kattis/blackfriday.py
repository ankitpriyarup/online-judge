from collections import Counter
n = int(input())
xs = [int(x) for x in input().split()]
c = Counter(xs)
vs = [k for k, v in c.most_common() if v == 1]
vs.sort()

if vs:
    print(1 + xs.index(vs[-1]))
else:
    print('none')

