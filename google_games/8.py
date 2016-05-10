from itertools import permutations

score = [0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600]

grid = range(1, 10)
best = 100000
for p in permutations(grid):
    g = [[p[0], p[1], p[2]], [p[3], p[4], p[5]], [p[6], p[7], p[8]]]
    ans = 0
    for row in g:
        ans += score[sum(row)]
    for j in range(3):
        s = 0
        for i in range(3):
            s += g[i][j]

        ans += score[s]

    ans += score[g[0][0] + g[1][1] + g[2][2]]
    ans += score[g[2][0] + g[1][1] + g[0][2]]

    best = min(best, ans)

print(best)
