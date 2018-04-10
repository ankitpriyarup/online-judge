from collections import Counter
s = input()
c = Counter(s)
odd = 0
for x in c:
    if c[x] % 2 == 1:
        odd += 1

print(max(0, odd - 1))
