# bounds on serving size for a package
# (500, 450) -> (1, 1)
# (10, 55) -> (5, 6)

#      1  2  3  4  5  6
#  9x  9 18 27 36 45 54
# 11x 11 22 33 44 55 66

def lower(need, package):
    # Find the largest x such that 0.9 * x * need <= package <= 1.1 * x * need
    lo = 0
    hi = int(1e8)
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if 10 * package <= 11 * mid * need:
            hi = mid
        else:
            lo = mid

    return hi

def upper(need, package):
    # Find the largest x such that 0.9 * x * need <= package <= 1.1 * x * need
    lo = 0
    hi = int(1e8)
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if 9 * mid * need <= 10 * package:
            lo = mid
        else:
            hi = mid

    return lo

def get_bounds(need, package):
    l = lower(need, package)
    u = upper(need, package)
    if l <= u:
        return (l, u)

def intersect(a, b):
    if a[0] > b[1] or a[1] < b[0]:
        return None

    return (max(a[0], b[0]), min(a[1], b[1]))

def has_intersection(ints):
    a = ints[0]
    for i in ints:
        if a is None:
            break
        a = intersect(a, i)

    return a is not None

def solve():
    n, p = map(int, input().split())
    req = list(map(int, input().split()))
    have = [list(map(int, input().split())) for _ in range(n)]

    for i in range(n):
        new_row = []
        for j in range(p):
            t = get_bounds(req[i], have[i][j])
            if t is not None:
                new_row.append(t)

        have[i] = new_row
        have[i].sort()

    ptrs = [0 for _ in range(n)]
    ans = 0
    while all(ptrs[i] < len(have[i]) for i in range(n)):
        if has_intersection([have[i][ptrs[i]] for i in range(n)]):
            ptrs = [x + 1 for x in ptrs]
            ans += 1
        else:
            move = 0
            for i in range(n):
                if have[i][ptrs[i]][1] < have[move][ptrs[move]][1]:
                    move = i

            ptrs[move] += 1

    return ans

def main():
    t = int(input())
    for tt in range(t):
        print('Case #{}: {}'.format(tt + 1, solve()))

main()
