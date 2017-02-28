from collections import deque
from fractions import Fraction

def sq_dist(x1, y1, x2, y2):
    xd = x2 - x1
    yd = y2 - y1

    return xd * xd + yd * yd

def calc(frac, src_rad, dest_rad):
    neg = frac > 0
    ratio = Fraction(src_rad, dest_rad)

    return (-1 if neg else 1) * ratio * abs(frac)

def main():
    n = int(input())
    gears = []
    for _ in range(n):
        x, y, r = map(int, input().split())

        gears.append((x, y, r))

    graph = [list() for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            rad_dist = gears[i][2] + gears[j][2]
            rad_dist *= rad_dist

            cent_dist = sq_dist(gears[i][0], gears[i][1], gears[j][0], gears[j][1])

            if rad_dist == cent_dist:
                graph[i].append(j)
                graph[j].append(i)

    q = deque([0])

    speeds = [Fraction(0, 1) for _ in range(n)]
    speeds[0] = Fraction(1, 1)

    valid = True
    while q:
        cur = q.popleft()
        frac = speeds[cur]
        if not valid:
            break

        for neighbor in graph[cur]:
            n_speed = calc(frac, gears[cur][2], gears[neighbor][2])
            if speeds[neighbor] == Fraction(0, 1):
                speeds[neighbor] = n_speed
                q.append(neighbor)
            else:
                if speeds[neighbor] != n_speed:
                    valid = False
                    break

    if not valid:
        print("The input gear cannot move.")
    else:
        ans = speeds[-1]
        if ans == Fraction(0, 1):
            print("The input gear is not connected to the output gear.")
        else:
            print('{}:{}'.format(ans.numerator, ans.denominator))

main()
