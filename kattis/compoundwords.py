import sys

words = set()
for line in sys.stdin:
    for word in line.strip().split():
        words.add(word)

res = set()
for x in words:
    for y in words:
        if x == y:
            continue
        res.add(x + y)

res = list(res)
res.sort()
for x in res:
    print(x)
