def works(bribes, a):
    l = a[0] + bribes
    b = bribes
    for r in a[1:]:
        if r >= l:
            b -= r - l + 1
    return b >= 0

def main():
    n = int(raw_input())
    a = map(int, raw_input().split())
    l = a[0]
    rest = reversed(sorted(a[1:]))

    if l > max(a[1:]):
        print 0
        return

    lo = 0
    hi = sum(a)
    while lo + 1 < hi:
        # number of bribes
        mid = (lo + hi) / 2
        if works(mid, a):
            hi = mid
        else:
            lo = mid
    print hi

if __name__ == '__main__':
    main()
