score = {'X': 1, 'O': -1, '.': 0}
def works(g, x, y):
    if x + 5 <= 10:
        cur = 0
        for d in range(5):
            cur += score[g[x+d][y]]
        if cur >= 4:
            return True

    if y + 5 <= 10:
        cur = sum(score[g[x][y + d]] for d in range(5))
        if cur >= 4:
            return True

    if x + 5 <= 10 and y + 5 <= 10:
        cur = sum(score[g[x + d][y + d]] for d in range(5))
        if cur >= 4:
            return True

    if x - 5 >= -1 and y + 5 <= 10:
        cur = sum(score[g[x - d][y + d]] for d in range(5))
        if cur >= 4:
            return True

    return False

grid = []
for _ in range(10):
    grid.append(input())

o = False
for i in range(10):
    for j in range(10):
        if works(grid, i, j):
            o = True

print('YES' if o else 'NO')
