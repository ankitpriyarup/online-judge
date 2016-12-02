def works(t, w, l, h, r):
    s = 0
    for hi, ri in zip(h, r):
        height = hi + ri * t
        if height >= l:
            s += height

    return s >= w

def main():
    n, w, l = map(int, input().strip().split())
    h = []
    r = []
    for _ in range(n):
        a, b = map(int, input().strip().split())
        h.append(a)
        r.append(b)

    if works(0, w, l, h, r):
        print(0)
    else:
        lo = 0
        hi = 10**18 + 1

        while lo + 1 < hi:
            mid = lo + (hi - lo) // 2
            if works(mid, w, l, h, r):
                hi = mid
            else:
                lo = mid

        print(hi)

main()
