def main():
    r, c = map(int, input().split())
    grid = []
    for _ in range(r):
        grid.append(list(input()))

    for j in range(c):
        apples = 0
        for i in range(r):
            if grid[i][j] == 'a':
                grid[i][j] = '.'
                apples += 1
            elif grid[i][j] == '#':
                for k in range(apples):
                    grid[i - k - 1][j] = 'a'
                apples = 0

        for k in range(apples):
            grid[r - k - 1][j] = 'a'

    for row in grid:
        print(''.join(row))

main()
