from fractions import Fraction

n, t = map(int, input().split())

tri = []
for row in range(n):
    arr = [0] * (row + 1)
    tri.append(arr)

tri[0][0] = 2048 * t

ans = 0
for i, row in enumerate(tri):
    for j, cell in enumerate(row):
        if cell >= 2048:
            ans += 1
            excess = cell - 2048
            if i + 1 < n:
                tri[i + 1][j] += excess // 2
                tri[i + 1][j + 1] += excess // 2

            row[j] = 2048

print(ans)
