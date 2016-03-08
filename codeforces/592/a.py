grid = []
for _ in xrange(8):
    grid.append(raw_input())

a, b = 8, 8
filled_top = [False for _ in range(8)]
for row in xrange(8):
    for col in xrange(8):
        if grid[row][col] == 'W' and not filled_top[col]:
            a = min(row, a)
        if grid[row][col] != '.':
            filled_top[col] = True

filled_bot = [False for _ in range(8)]
for row in xrange(7, -1, -1):
    for col in xrange(8):
        if grid[row][col] == 'B' and not filled_bot[col]:
            b = min(7 - row, b)
        if grid[row][col] != '.':
            filled_bot[col] = True

print 'A' if a <= b else 'B'
