n = int(input())
grid = [input() for _ in range(n)]
works = True
moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
for i in range(n):
    for j in range(n):
        around = 0
        for dx, dy in moves:
            nx, ny = i + dx, j + dy
            if 0 <= nx < n and 0 <= ny < n:
                around += grid[nx][ny] == 'o'
        if around % 2 == 1:
            works = False

print('YES' if works else 'NO')
