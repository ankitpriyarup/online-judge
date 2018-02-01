def is_perm(r, n):
    return list(sorted(r)) == list(range(n))

n = int(input())
grid = []
for _ in range(n):
    row = [int(c, 36) for c in input()]
    grid.append(row)

reduced = True
for i in range(n):
    reduced = reduced and grid[0][i] == i
    reduced = reduced and grid[i][0] == i

latin = True
for i in range(n):
    latin = latin and is_perm(grid[i], n)
    col = [grid[x][i] for x in range(n)]
    latin = latin and is_perm(col, n)

if not latin:
    print('No')
elif not reduced:
    print('Latin')
else:
    print('Reduced')
