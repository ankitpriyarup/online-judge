#!/usr/bin/env python3

def solve_prefix(a):
    tot = 0
    ans = 0.0
    for i, x in enumerate(a):
        tot += x
        ans = max(ans, tot / (i + 1))
    return ans

n = int(input())
a = list(map(int, input().split()))
ans = max(solve_prefix(a), solve_prefix(reversed(a)))

print('{:.9f}'.format(ans))
