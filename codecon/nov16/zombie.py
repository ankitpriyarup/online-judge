def corners(x, y):
    if x % 10 == 0 and y % 10 == 0:
        yield ((x, y), 0)
    elif x % 10 == 0:
        yield ((x, y - (y % 10)), y % 10)
        yield ((x, y + (10 - (y % 10))), (10 - (y % 10)))
    else:
        yield ((x - (x % 10), y), x % 10)
        yield ((x + (10 - (x % 10)), y), (10 - (x % 10)))

def dist(x1, y1, x2, y2):
    ans = float('inf')
    for corner1, d1 in corners(x1, y1):
        for corner2, d2 in corners(x2, y2):
            ans = min(ans, d1 + d2 + abs(corner1[0] - corner2[0]) + abs(corner1[1] - corner2[1]))

    return ans

def main():
    x, y, t, n = map(int, input().split())
    candidates = []
    for _ in range(n):
        name, cx, cy = input().split()
        cx, cy = int(cx), int(cy)

        candidates.append((name, 2 * dist(x, y, cx, cy)))

    candidates.sort(key= lambda x: x[1])

    names = set()
    for name, cost in candidates:
        if cost <= t:
            names.add(name)
            t -= cost

    names = list(names)
    names.sort()
    if len(names) == 0:
        print(0)
    else:
        print(len(names), ' '.join(names))

main()
