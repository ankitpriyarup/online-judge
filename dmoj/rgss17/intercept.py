def mult(a, b):
    d1, d2 = len(a), len(b)
    c = [0] * (d1 + d2 - 1)

    for i in range(d1):
        for j in range(d2):
            c[i + j] += a[i] * b[j]

    return c

def run(poly, x):
    base = 1
    ans = 0
    for c in poly:
        ans += base * c
        base *= x

    return ans

def main():
    n = int(input())
    roots = map(int, input().split())
    x, y = map(int, input().split())

    poly = [1]
    for root in roots:
        poly = mult(poly, [-root, 1])

    actual = run(poly, x)
    factor = y // actual
    out = list(str(c * factor) for c in reversed(poly))

    print(' '.join(out))

q = int(input())
for _ in range(q):
    main()

