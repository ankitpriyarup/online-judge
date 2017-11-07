from collections import *
from fractions import Fraction

def main():
    n = int(input())
    gears = []
    for _ in range(n):
        x, y, r = map(int, input().split())
        gears.append((x, y, r))

    graph = defaultdict(list)
    for u in range(n):
        for v in range(u + 1, n):
            xd = gears[u][0] - gears[v][0]
            yd = gears[u][1] - gears[v][1]
            rs = gears[u][2] + gears[v][2]
            if xd * xd + yd * yd == rs * rs:
                graph[u].append(v)
                graph[v].append(u)

    rots = [None for _ in range(n)]
    rots[0] = Fraction(1, 1)
    q = deque([0])
    deadlock = False
    while not deadlock and q:
        cur = q.popleft()

        for x in graph[cur]:
            exp = Fraction(gears[x][2], gears[cur][2]) * -rots[cur]
            if rots[x] is None:
                rots[x] = exp
                q.append(x)
            elif rots[x] != exp:
                deadlock = True
                break

    if deadlock:
        print(-1)
    elif rots[-1] is None:
        print(0)
    else:
        f = rots[-1] / rots[0]
        a = f.numerator
        b = f.denominator
        if a < 0:
            a, b = -a, -b

        print(a, b)

main()
