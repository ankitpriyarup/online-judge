t = int(input())
for _ in range(t):
    r, c, o = map(int, input().split())
    grid = []
    for _ in range(r):
        grid.append(list(map(int, input())))

    for _ in range(o):
        a, b = input().split()
        b = int(b)
        if a == 'R':
            for x in range(0, r, b):
                for y in range(0, c):
                    grid[x][y] = 1 - grid[x][y]
        else:
            for y in range(0, c, b):
                for x in range(0, r):
                    grid[x][y] = 1 - grid[x][y]
    for row in grid:
        print(''.join(map(str, row)))
