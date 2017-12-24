from math import sqrt
def main():
    n = int(input())
    pts = [tuple(map(float, input().split())) for _ in range(n)]
    area = int(input())

    cur_area = pts[0][0] * pts[-1][1] - pts[0][1] * pts[-1][0]
    for i in range(1, n):
        cur_area += pts[i][0] * pts[i - 1][1] - pts[i][1] * pts[i - 1][0]

    cur_area = abs(cur_area) / 2.0

    center = tuple(sum(pt[i] for pt in pts) / n for i in range(2))
    scale = sqrt(area / cur_area)
    pts = [tuple(scale * (pt[i] - center[i]) + center[i] for i in range(2)) for pt in pts]
    minx = min(x for x, _ in pts)
    miny = min(y for _, y in pts)

    for x, y in pts:
        print(x - minx, y - miny)

main()
