def l1(a, b):
    dx = a[0] - b[0]
    dy = a[1] - b[1]
    return abs(dx) + abs(dy)

def to_road(a, b, x, y):
    if x % a == 0 or y % b == 0:
        yield ((x, y), 0)
        return

    x1 = x - (x % a)
    x2 = x1 + a

    y1 = y - (y % b)
    y2 = y1 + b

    assert x1 <= x <= x2
    assert y1 <= y <= y2

    new_dist = min(x - x1, x2 - x, y - y1, y2 - y)
    if x - x1 == new_dist:
        yield ((x1, y), new_dist)
    if x2 - x == new_dist:
        yield ((x2, y), new_dist)
    if y - y1 == new_dist:
        yield ((x, y1), new_dist)
    if y2 - y == new_dist:
        yield ((x, y2), new_dist)

def corners(a, b, p):
    if p[0] % a == 0:
        y1 = p[1] - (p[1] % b)
        y2 = y1 + b
        yield ((p[0], y1), p[1] - y1)
        yield ((p[0], y2), y2 - p[1])

    if p[1] % b == 0:
        x1 = p[0] - (p[0] % a)
        x2 = x1 + a
        yield ((x1, p[1]), p[0] - x1)
        yield ((x2, p[1]), x2 - p[0])

def on_road(a, b, p0, p1):
    if p0[0] == p1[0] and p0[0] % a == 0:
        return abs(p0[1] - p1[1])
    elif p0[1] == p1[1] and p0[1] % b == 0:
        return abs(p0[0] - p1[0])

    # get thee to a corner
    ans = float('inf')
    for c1, d1 in corners(a, b, p0):
        for c2, d2 in corners(a, b, p1):
            ans = min(ans, d1 + d2 + l1(c1, c2))

    return ans

def main():
    a, b, x1, y1, x2, y2 = map(int, input().split())
    ans = (float('inf'), float('inf'))
    for p1, d1 in to_road(a, b, x1, y1):
        for p2, d2 in to_road(a, b, x2, y2):
            grass_dist = d1 + d2
            road_dist = on_road(a, b, p1, p2)
            if (grass_dist, road_dist) < ans:
                ans = (grass_dist, road_dist)

    print(sum(ans))

T = int(input())
for _ in range(T):
    main()
