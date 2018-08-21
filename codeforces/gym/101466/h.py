n = int(input())
c = [[' ' for _ in range(2 * n + 1)] for _ in range(n)]
for i in range(n):
    for j in [0, n - 1, n + 1, 2 * n]:
        c[i][j] = '*'

for j in range(n):
    c[n - 1][j] = '*'

for j in range(n + 1, 2 * n + 1):
    c[0][j] = '*'

for row in c:
    print(''.join(row))
