from collections import Counter
def normalize(s):
    p1 = (s[0], s[1])
    p2 = (s[2], s[3])
    return p1 + p2 if p1 <= p2 else p2 + p1

def main():
    segs = [normalize(tuple(map(int, input().split()))) for _ in range(4)]
    if len(set(segs)) != 4:
        print('NO')
        return

    points = []
    for x1, y1, x2, y2 in segs:
        if (x1, y1) == (x2, y2):
            print('NO')
            return

        points.append((x1, y1))
        points.append((x2, y2))

    c = Counter(points)
    xs = Counter(p[0] for p in points)
    ys = Counter(p[1] for p in points)
    if any(c[p] != 2 for p in c):
        print('NO')
        return

    if any(xs[x] != 4 for x in xs):
        print('NO')
        return
        
    if any(ys[y] != 4 for y in ys):
        print('NO')
        return

    if len(set(points)) != 4:
        print('NO')
        return

    print('YES')

main()
