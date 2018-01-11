def main():
    grid = []
    for _ in range(8):
        grid.append(input())

    if all(all(c == 'B' for c in row) for row in grid):
        print('8')
        return

    rows = []
    for i, row in enumerate(grid):
        if all(c == 'B' for c in row):
            rows.append(i)

    cols = []
    for j in range(8):
        if all(grid[i][j] == 'B' for i in range(8)):
            cols.append(j)

    print(len(rows) + len(cols))

main()
