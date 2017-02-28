from collections import deque
import sys

fave = 1362


def valid(x, y):
    val = x * x + 3 * x + 2 * x * y + y + y * y
    val += fave
    count = 0
    while val > 0:
        if val % 2 == 1:
            count += 1
        val //= 2

    return count % 2 == 0


def neighbors(x, y):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    for d in range(4):
        nx = x + dx[d]
        ny = y + dy[d]
        if 0 <= nx and 0 <= ny and valid(nx, ny):
            yield nx, ny


def main():
    start = (1, 1)
    q = deque([start])
    visited = set([start])

    level = 0
    while q:
        if level == 50:
            break
        sz = len(q)
        for _ in range(sz):
            cur = q.popleft()

            if cur == (31, 39):
                print("LEVEL", level)
                sys.exit(0)

            for x, y in neighbors(*cur):
                if (x, y) not in visited:
                    visited.add((x, y))
                    q.append((x, y))

        level += 1

    print(level)

    print(len(visited))


main()
