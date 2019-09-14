def euclid(a, b):
    if b == 0:
        return a, 1, 0
    d, y, x = euclid(b, a % b)
    return d, x, y - (a // b) * x

def gcd(a, b):
    d, _, _ = euclid(a, b)
    return d

def crt(p1, p2):
    a, m = p1
    b, n = p2
    if a < 0 or b < 0:
        return (-1, -1)

    d = gcd(m, n)
    if (a - b) % d != 0:
        return (-1, -1)

    g, x, y = euclid(m // d, n // d)
    l = (a - b) // d
    ret_mod = m // d * n
    l %= ret_mod
    ret = b + n * l * y
    ret %= ret_mod

    return (ret, ret_mod)

def main():
    a, m, b, n = map(int, input().split())
    res = crt((a, m), (b, n))
    if res[0] < 0:
        print('no solution')
    else:
        print(*res)

T = int(input())
for _ in range(T):
    main()
