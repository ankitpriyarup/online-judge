r, c, zr, zc = map(int, input().split())
grid = [input() for _ in range(r)]
out = [[' ' for _ in range(c * zc)] for _ in range(r * zr)]

for i in range(r):
    for j in range(c):
        k = grid[i][j]
        for rr in range(i * zr, (i + 1) * zr):
            for cc in range(j * zc, (j + 1) * zc):
                out[rr][cc] = k

for row in out:
    print(''.join(row))
