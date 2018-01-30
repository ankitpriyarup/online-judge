from collections import Counter
from functools import reduce

n = int(input())
sentence = input().split()
m = int(input())
corr = Counter()
total = Counter()
trans = {}
for _ in range(m):
    d, e, c = input().split()
    if c.startswith('co'):
        corr[d] += 1

    trans[d] = e
    total[d] += 1

tot = reduce(lambda x, y: x * y, [total[w] for w in sentence])
counts = [corr[w] for w in sentence]
c = reduce(lambda x, y: x * y, counts)

if tot == 1:
    print(' '.join(trans[w] for w in sentence))
    if c == 1:
        print('correct')
    else:
        print('incorrect')
else:
    print(c, 'correct')
    print(tot - c, 'incorrect')
