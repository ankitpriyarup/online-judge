grid = [input() for _ in range(3)]
a = '\n'.join(grid)
for _ in range(2):
    # transpose and flip
    new_grid = [['.' for _ in range(3)] for _ in range(3)]
    for i in range(3):
        for j in range(3):
            new_grid[i][j] = grid[j][i]
    # transpose, reverse rows
    grid = [row[::-1] for row in new_grid]

b = '\n'.join(''.join(c for c in row) for row in grid)
if a == b:
    print('YES')
else:
    print('NO')
