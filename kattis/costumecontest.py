from collections import Counter
n = int(input())
c = Counter(input() for _ in range(n))
freqs = c.most_common()
f = freqs[-1][1]
ans = [x[0] for x in freqs if x[1] == f]
ans.sort()
for s in ans:
    print(s)
