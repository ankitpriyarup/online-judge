from collections import Counter
hand = list(input().split())
c = Counter(h[0] for h in hand)
print(c.most_common()[0][1])
