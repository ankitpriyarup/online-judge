#!/bin/python3

import sys

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
a.sort()

ans = int(1e18)
for i in range(1, n):
    ans = min(ans, a[i] - a[i - 1])
    
print(ans)
