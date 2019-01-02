r, c, k = map(int ,input().split())
grid = [list(input().split()) for _ in range(r)]

x, y = 0, 0
out = [grid[x][y]]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for _ in range(k):
    opts = []
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] != grid[x][y]:
            opts.append((grid[nx][ny], nx, ny))

    opts.sort()
    v, x, y = opts[0]
    out.append(v)
print(''.join(out))
