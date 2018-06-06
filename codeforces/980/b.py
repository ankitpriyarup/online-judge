def main():
    n, k = map(int, input().split())
    grid = [['.' for _ in range(n)] for _ in range(4)]

    r = 1
    if k >= n - 2:
        grid[1] = ['.'] + ['#'] * (n - 2) + ['.']
        k -= n - 2
        r = 2

    c = 1
    while k > 1:
        grid[r][c] = '#'
        grid[r][n - 1 - c] = '#'
        c += 1
        k -= 2

    if k == 1:
        grid[r][n // 2] = '#'

    print('YES')
    for row in grid:
        print(''.join(row))

main()
