n, k = map(int, input().split())
p = [int(x) - 1 for x in input().split()]
pos = [-1 for _ in range(n)]
for i, x in enumerate(p):
    pos[x] = i

poss = True
for i, x in enumerate(p):
    poss &= pos[i] % k == i % k
print('YES' if poss else 'NO')
