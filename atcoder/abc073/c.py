s = set()
n = int(input())
for _ in range(n):
    x = int(input())
    if x in s:
        s.remove(x)
    else:
        s.add(x)

print(len(s))
