import math

def main():
    INF = int(5e18)
    a, b, c = map(int, input().split())

    # solve ax + by = d
    # multiply by -c to get ans

    # solve ax + by = -c
    g = math.gcd(a, b)
    if c % g != 0:
        print(-1)
        return

    a //= g
    b //= g
    c //= g

    # solve ax + by = g
    # multiply by -c

    s1, t1 = 1, 0
    s2, t2 = 0, 1

    r1, r2 = a, b

    while r2 != 0:
        q = r1 // r2
        s1, s2 = s2, s1 - q * s2
        t1, t2 = t2, t1 - q * t2
        r1, r2 = r2, r1 % r2

    if b < 0:
        b *= -1
        a *= -1
        c *= -1

    x, y = s1, t1
    if -c * x < INF:
        while -c * x <= INF:
            if -INF <= -c * x <= INF and -INF <= -c * y <= INF:
                print(-c * x, -c * y)
                return

            x += b
            y -= a
    else:
        while -INF <= -c * x:
            if -INF <= -c * x <= INF and -INF <= -c * y <= INF:
                print(-c * x, -c * y)
                return

            x -= b
            y += a

    print(-1)

main()
