from collections import Counter

def is_rect(pts, a, b):
    c1 = Counter(p[0] for p in pts)
    c1[a] += 1
    c2 = Counter(p[1] for p in pts)
    c2[b] += 1
    return len(c1) == 2 and len(c2) == 2 and all(y == 2 for x, y in c1.most_common()) and all(y == 2 for x, y in c2.most_common())

def main():
    pts = []
    for _ in range(3):
        a, b = map(int, input().split())
        pts.append((a, b))

    for xi in range(3):
        for yi in range(3):
            if is_rect(pts, pts[xi][0], pts[yi][1]):
                print(pts[xi][0], pts[yi][1])
                return

main()
