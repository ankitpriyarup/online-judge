n, m = map(int, input().split())
d = {}
for _ in range(n):
    a, b = input().split()
    d[b] = a

for _ in range(m):
    a, b = input().split()
    print('{} {} #{}'.format(a, b, d[b[:-1]]))
