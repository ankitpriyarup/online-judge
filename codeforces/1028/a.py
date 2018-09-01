def main():
    n, m = map(int, input().split())
    l, r, t, b = m + 1, -1, n + 1, -1
    grid = [input() for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'B':
                l = min(l, j)
                r = max(r, j)
                t = min(t, i)
                b = max(b, i)
    x = (l + r) // 2
    y = (t + b) // 2
    print(y + 1, x + 1)

main()
