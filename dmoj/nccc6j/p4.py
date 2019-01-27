from collections import Counter
n = int(input())
s = Counter(input() for _ in range(n))
f = s.most_common()
m = {'Deluxe Tuna Bitz': 0, 'Bonito Bitz': 1, 'Sashimi': 2, 'Ritzy Bitz': 3}
f.sort(key=lambda s: (-s[1], m[s[0]]))
for k, v in f:
    print(k, v)
