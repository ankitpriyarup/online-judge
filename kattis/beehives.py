EPS = 1e-7
def dist(p, q):
    dx, dy = p[0] - q[0], p[1] - q[1]
    d = dx * dx + dy * dy
    if d < EPS:
        return float('inf')
    return d

while True:
    d, n = input().split()
    d = float(d)
    n = int(n)
    if n == 0:
        break

    pos = [tuple(map(float, input().split())) for _ in range(n)]
    sweet = 0
    for i in range(n):
        dists = [dist(pos[i], p) for p in pos]
        if all(x > d * d for x in dists):
            sweet += 1

    print('{} sour, {} sweet'.format(n - sweet, sweet))
