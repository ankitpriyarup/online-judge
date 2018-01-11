k, p, x = 0, 0, 0
def f(m):
    if m == 0:
        return float('inf')

    return float(k * p) / m + float(m * x)

def main():
    global k, p, x
    k, p, x = map(int, input().split())
    lo = 0
    hi = int(1e9)
    while lo + 5 < hi:
        m = (lo + hi) // 2
        if f(m) < f(m - 1):
            lo = m
        else:
            hi = m

    ans = min([f(x) for x in range(lo, hi + 1)])
    print('{:.3f}'.format(ans))

main()
