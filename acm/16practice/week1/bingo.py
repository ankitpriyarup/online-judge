from itertools import combinations


def main():
    N = int(input())
    for _ in range(N):
        b, i, n, g, o, x, y = map(int, input().split())
        counts = [b, i, n, g, o]
        grid = [[] for _ in range(x)]
        for _ in range(5):
            row = input().split()
            for i, chunk in enumerate(row):
                grid[i].append(chunk)

        ans = int(1e9)
        for special in combinations(grid, y):
            merged = [['X' if any(item[i][j] == 'X' for item in special) else 'O' for j in range(5)] for i in range(5)]
            merged[2][2] = 'O'
            colsums = [sum(1 if merged[i][j] == 'X' else 0 for i in range(5)) for j in range(5)]

            cur = sum(max(0, needed - have) for needed, have in zip(colsums, counts))
            ans = min(ans, cur)

        print(ans)

main()
