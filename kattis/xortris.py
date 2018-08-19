def greedy(r):
    a = [c == 'X' for c in r]
    n = len(a)
    for i in range(n):
        if a[i]:
            if i + 4 > n:
                return False
            for j in range(4):
                a[i + j] = not a[i + j]

    return True

n, m = map(int, input().split())
g = [input() for _ in range(n)]
freq = [0, 0]
for i, row in enumerate(g):
    for j, c in enumerate(row):
        if c == 'X':
            freq[(i + j) % 2] += 1

if n == 1:
    poss = greedy(g[0])
elif m == 1:
    poss = greedy([r[0] for r in g])
elif n == 2 and m == 2:
    poss = sum(freq) == 0 or sum(freq) == 4
else:
    poss = sum(freq) % 2 == 0

print('possible' if poss else 'impossible')
