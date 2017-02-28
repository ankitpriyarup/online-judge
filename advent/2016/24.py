import itertools
from collections import deque


def main():
    fin = open('24.in', 'r')
    board = []
    sx, sy = -1, -1
    for line in fin:
        board.append(line.strip())

    # run a bfs from each number
    dist = [[-1 for _ in range(8)] for _ in range(8)]
    for v in range(8):
        sv = str(v)
        for i, row in enumerate(board):
            if sv in row:
                sx, sy = i, row.index(sv)
                break

        q = deque([(sx, sy)])
        visit = set([(sx, sy)])
        depth = 0

        while q:
            size = len(q)

            for _ in range(size):
                x, y = q.popleft()
                if board[x][y] in '01234567':
                    value = int(board[x][y])
                    dist[v][value] = depth

                for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                    nx = x + dx
                    ny = y + dy
                    if 0 <= nx < len(board) and 0 <= ny < len(board[nx]) \
                            and (nx, ny) not in visit and (not board[nx][ny] == '#'):
                        q.append((nx, ny))
                        visit.add((nx, ny))


            depth += 1

    print(dist)

    ans = float('inf')
    for combo in itertools.permutations(range(1, 8)):
        cur = dist[0][combo[0]]
        for i in range(1, 7):
            cur += dist[combo[i]][combo[i - 1]]

        cur += dist[combo[-1]][0]

        ans = min(ans, cur)

    print(ans)

main()
