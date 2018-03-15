from collections import Counter

n = int(input())
c = Counter()
for _ in range(n):
    a = list(map(int, input().split()))
    a.sort()
    c[tuple(a)] += 1

f = c.most_common()[0][1]
print(sum(f for x in c if c[x] == f))
