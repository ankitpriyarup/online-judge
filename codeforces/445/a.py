def main():
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(list(input()))

    chars = 'BW'
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                grid[i][j] = chars[(i + j) % 2]

    for row in grid:
        print(''.join(row))

main()
