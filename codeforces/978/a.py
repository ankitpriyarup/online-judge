n = int(input())
a = list(map(int, input().split()))
seen = set()
a = reversed(a)
b = []
for x in a:
    if x in seen:
        continue
    else:
        b.append(x)
        seen.add(x)
print(len(b))
print(' '.join(str(x) for x in reversed(b)))
