from itertools import permutations
from math import sqrt, ceil
import sys

sys.setrecursionlimit(1000000)

EPS = 1e-5
FACTOR = 3600.0


def dot(a, b):
    return a.real * b.real + a.imag * b.imag


def time_to(start, speed, dest, time):
    # p + vt = ut
    # (p + vt) (p + vt) = u^2 t^2
    # p^2 + 2pvt + v^2 t^2 = u^2 t^2
    # (v^2 - u^2) t^2 + (2pv) t + p^2 = 0
    v = dest[1]
    p = dest[0] + (time * v) - start

    a = dot(v, v) - speed * speed
    b = 2 * dot(p, v)
    c = dot(p, p)

    disc = b * b - 4 * a * c
    root1 = (-b + sqrt(disc)) / (2 * a)
    root2 = (-b - sqrt(disc)) / (2 * a)

    if root1 < EPS and root2 < EPS:
        return 0

    if root1 < EPS:
        root1 = float('inf')
    if root2 < EPS:
        root2 = float('inf')

    return min(root1, root2)


def solve(start, s, perm):
    cur = start
    time = 0.0
    for dest in perm:
        time += time_to(cur, s, dest, time)
        time += FACTOR

        cur = dest[0] + (dest[1] * time)

    return time + time_to(cur, s, (start, complex(0.0, 0.0)), time)


def main():
    case_num = 1
    while True:
        N = int(input())
        if N == 0:
            break

        sleighs = []
        for _ in range(N):
            x, y, vx, vy = map(float, input().split())
            pos = complex(x, y)
            velocity = complex(vx, vy) / FACTOR
            sleighs.append((pos, velocity))

        sx, sy, u = map(int, input().split())
        u /= FACTOR
        start = complex(sx, sy)

        ans = float('inf')
        for perm in permutations(sleighs):
            ans = min(ans, solve(start, u, perm))

        seconds = int(ceil((3600.0 / FACTOR) * ans))
        h, m = divmod(seconds, 3600)
        m, s = divmod(m, 60)

        print("Case {}: {} hour(s) {} minute(s) {} seconds"
              .format(case_num, h, m, s))

        case_num += 1

main()
