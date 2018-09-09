import sys
sys.setrecursionlimit(int(1e7))
n, m = map(int, input().split())
a = [[int(v) % 2 for v in input().split()] for _ in range(n)]
moves = []
for i in range(n):
    for j in range(m):
        if i == n - 1 and j == m - 1:
            break

        if a[i][j] == 1:
            if j == m - 1:
                moves.append((i + 1, j + 1, i + 2, j + 1))
                a[i + 1][j] ^= 1
            else:
                moves.append((i + 1, j + 1, i + 1, j + 2))
                a[i][j + 1] ^= 1

print(len(moves))
for move in moves:
    print(*move)
