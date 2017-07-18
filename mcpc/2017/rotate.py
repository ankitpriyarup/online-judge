target = [[1, 1, 1, 1], [1, 2, 2, 2], [1, 1, 2, 2], [1, 2, 2, 2]]
m1 = [[0, 0, 0, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 0]]
m2 = [[0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 1, 1], [1, 1, 1, 1]]
m3 = [[0, 1, 0, 1], [1, 0, 0, 0], [1, 1, 1, 0], [1, 1, 0, 0]]

maps = [m1, m2, m3]

def rotate(m):
    return list(zip(*m[::-1]))

def flip(m):
    return [row[::-1] for row in m]

def options(m):
    for i in range(4):
        yield m
        m = rotate(m)

    m = flip(m)

    for i in range(4):
        yield m
        m = rotate(m)

def g_sum(a, b, c):
    out = [[0 for _ in range(4)] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            out[i][j] = a[i][j] + b[i][j] + c[i][j]

    return out

def main():
    for i in options(m1):
        for j in options(m2):
            for k in options(m3):
                if g_sum(i, j, k) == target:
                    print(i)
                    print(j)
                    print(k)

main()
