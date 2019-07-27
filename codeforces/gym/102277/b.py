from collections import Counter

c = Counter(input())
even = all(v % 2 == 0 for _, v in c.items())
odd = all(v % 2 == 1 for _, v in c.items())
if even:
    print(0)
elif odd:
    print(1)
else:
    print(2)
