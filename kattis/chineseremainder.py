def euclid(a, b):
    """Returns g, x, y, such that ax + by = g, and g is GCD"""
    x, xx = 1, 0
    y, yy = 0, 1

    while b > 0:
        q = a // b
        a, b = b, a % b
        x, xx = xx, x - q * xx
        y, yy = yy, y - q * yy

    return a, x, y

def crt(a, b, n, m):
    _, x, y = euclid(n, m)
    ans = (a * y * m + b * x * n) % (n * m)
    return ans

T = int(input())
for _ in range(T):
    a, n, b, m = map(int, input().split())
    ans = crt(a, b, n, m)
    print(ans, n * m)
