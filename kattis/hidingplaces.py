from collections import deque

moves = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (-2, 1), (2, -1), (-2, -1)]

def to_chess(row, col):
    c = chr(col + ord('a'))
    r = str(row + 1)
    return c + r

def main():
    s = input()
    row = int(s[1]) - 1
    col = ord(s[0]) - ord('a')
    q = deque([(row, col)])
    vis = { (row, col): 0 }
    worst = 0
    while q:
        x, y = q.popleft()
        for dx, dy in moves:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 8 and 0 <= ny < 8 and (nx, ny) not in vis:
                dist = vis[(x, y)] + 1
                vis[(nx, ny)] = dist
                worst = max(worst, dist)
                q.append((nx, ny))

    tuples = [k for k, v in vis.items() if v == worst]
    tuples.sort(key=lambda p: (-p[0], p[1]))
    print(worst, ' '.join(to_chess(r, c) for r, c in tuples))


for _ in range(int(input())):
    main()
