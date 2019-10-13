#!/usr/bin/env python3

n = int(input())
"""
factorial = [1]
for i in range(1, 2 * n + 5):
    factorial.append(i * factorial[-1])
"""

catalan = [1, 1]
for i in range(2, n + 2):
    res = catalan[-1]
    res *= (2 * i - 1) * (2 * i)
    res //= i * (i + 1)
    catalan.append(res)

ans = catalan[n + 1]
print(ans)
