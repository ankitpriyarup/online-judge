from math import sqrt

T = int(input())
for _ in range(T):
    s = input()
    n = len(s)
    x = int(sqrt(n))
    while x * x < n:
        x += 1
    while x * x > n:
        x -= 1
    grid = [s[i:i+x] for i in range(0, n, x)]
    out = []
    for col in range(x - 1, -1, -1):
        for row in range(x):
            out.append(grid[row][col])
    print(''.join(out))
