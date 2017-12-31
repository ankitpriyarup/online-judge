def won(c, grid):
    for row in grid:
        if all(x == c for x in row):
            return True

    for col in range(3):
        if all(grid[i][col] == c for i in range(3)):
            return True

    if all(grid[i][i] == c for i in range(3)):
        return True

    if all(grid[2 - i][i] == c for i in range(3)):
        return True

    return False

def main():
    grid = [input() for _ in range(3)]
    xs = sum(row.count('X') for row in grid)
    os = sum(row.count('0') for row in grid)
    xw = won('X', grid)
    ow = won('0', grid)

    if not (0 <= xs - os <= 1) or (xw and (ow or xs == os)) or (ow and xs > os):
        print('illegal')
    elif xw:
        print('the first player won')
    elif ow:
        print('the second player won')
    elif all('.' not in row for row in grid):
        print('draw')
    elif xs > os:
        print('second')
    else:
        print('first')

main()
