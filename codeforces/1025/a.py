from collections import Counter

n = int(input())
c = Counter(input())
if n == 1 or c.most_common()[0][1] >= 2:
    print('Yes')
else:
    print('No')
