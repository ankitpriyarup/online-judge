from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def main():
    line = sys.stdin.readline().strip()[1:-1]
    graph = defaultdict(set)
    dirs = 'NESW'
    moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    stk = [(0, 0)]
    for c in line:
        print(stk)
        x, y = stk.pop()
        print('encountered {} at {}, {}'.format(c, x, y))
        if c in dirs:
            d = dirs.index(c)
            dx, dy = moves[d]
            nx, ny = x + dx, y + dy
            graph[(x, y)].add((nx, ny))
            graph[(nx, ny)].add((x, y))
            x, y = nx, ny
            stk.append((x, y))
        elif c in '(':
            stk.append((x, y))
            stk.append((x, y))
        elif c in '|':
            stk.append(stk[-1])
        elif c in ')':
            continue
        else:
            assert(False, 'found {}'.format(c))

    dq = deque([(0, 0)])
    dist = defaultdict(lambda: float('inf'))
    dist[(0, 0)] = 0
    ans = 0
    ans2 = 0
    while dq:
        x, y = dq.popleft()
        cur_dist = dist[(x, y)]

        if cur_dist >= 1000:
            ans2 += 1

        for nx, ny in graph[(x, y)]:
            if cur_dist + 1 < dist[(nx, ny)]:
                dist[(nx, ny)] = cur_dist + 1
                ans = max(ans, cur_dist + 1)
                dq.append((nx, ny))

    print(ans)
    print(ans2)

main()
