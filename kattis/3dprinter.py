"""

a
ab
abcd
abcdefgh
8


1: 1 (print)
2: 2 (doesnt matter)
3: 4 (clone print print)
4: 8
"""

def f(days):
    """Max # can create in d days"""
    return (1 << (days - 1))

def main():
    n = int(input())
    lo = 0
    hi = n
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if f(mid) >= n:
            hi = mid
        else:
            lo = mid

    print(hi)

main()
