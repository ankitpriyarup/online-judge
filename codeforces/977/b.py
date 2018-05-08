from collections import Counter
n = int(input())
s = input()
c = Counter()
for i in range(1, n):
    t = s[i - 1:i + 1]
    c[t] += 1

print(c.most_common()[0][0])
