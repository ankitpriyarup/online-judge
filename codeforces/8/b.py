from collections import deque

def main():
    pos = (0, 0)
    s = input()
    n = len(s)
    moves = {'L': (0, -1), 'R': (0, 1), 'U': (-1, 0), 'D': (1, 0)}
    safe = set()
    for c in s:
        dx, dy = moves[c]
        pos = (pos[0] + dx, pos[1] + dy)
        safe.add(pos)

    goal = pos
    pos = (0, 0)
    q = deque([pos])
    lvl = 0
    dist = -1
    vis = set([pos])

    while q:
        if dist != -1:
            break

        sz = len(q)
        for _ in range(sz):
            cur = q.popleft()
            if cur == goal:
                dist = lvl
                break

            for _, v in moves.items():
                dx, dy = v
                npos = (cur[0] + dx, cur[1] + dy)
                if npos in safe and npos not in vis:
                    vis.add(npos)
                    q.append(npos)

        lvl += 1

    print('OK' if dist == n else 'BUG')

main()
