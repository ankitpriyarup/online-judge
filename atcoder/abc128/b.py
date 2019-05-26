n = int(input())
r = []
for i in range(n):
    s, p = input().split()
    p = int(p)
    r.append((s, -p, i))

r.sort()
for _, _, i in r:
    print(i + 1)
