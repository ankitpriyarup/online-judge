def score(grid, tl):
    n = len(grid)
    ans = 0
    for i in range(n):
        for j in range(n):
            ans += int(grid[i][j]) ^ (i & 1) ^ (j & 1) ^ tl

    return ans

def main():
    n = int(input())
    first = True
    grids = []
    for _ in range(4):
        if not first:
            input()
        first = False
        grids.append([input() for _ in range(n)])

    a = [score(grid, 0) for grid in grids]
    b = [score(grid, 1) for grid in grids]

    ans = float('inf')
    for i in range(4):
        for j in range(i + 1, 4):
            ans = min(ans, sum(a) - a[i] - a[j] + b[i] + b[j])

    print(ans)

main()
