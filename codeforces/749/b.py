import itertools


def add(a, b):
    return (a[0] + b[0], a[1] + b[1])


def sub(a, b):
    return (a[0] - b[0], a[1] + b[1])


def parallelogram(p, d):
    a, b, c = p
    for x, y, z, w in itertools.permutations([a, b, c, d]):
        print(x, y, z, w)
        if x[0] - y[0] == z[0] - w[0] \
           and x[0] - w[0] == y[0] - z[0] \
           and x[0] - y[0] == z[0] - w[0] \
           and x[1] - w[1] == y[1] - z[1]:
            return True

    return False


def main():
    points = []
    for _ in range(3):
        x, y = map(int, input().split())
        points.append((x, y))

    out = []
    for i in range(3):
        for j in range(i + 1, 3):
            v1 = sub(points[i], points[j])
            v2 = sub(points[j], points[i])

            for p in points:
                for v in [v1, v2]:
                    np = add(p, v)
                    if np not in points and parallelogram(points, np):
                        out.append(np)

    print(len(out))
    for x, y in out:
        print(x, y)


main()
