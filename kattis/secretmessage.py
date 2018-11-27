T = int(input())
for _ in range(T):
    s = input()
    n = len(s)
    x = 1
    while x * x < n:
        x += 1

    pad = '*' * (x * x - n)
    s += pad
    grid = [s[i:i+x] for i in range(0, len(s), x)]
    o = []
    for col in range(x):
        for row in range(x - 1, -1, -1):
            if grid[row][col] == '*':
                continue
            o.append(grid[row][col])
    print(''.join(o))

