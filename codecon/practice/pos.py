#Problem        : 2016 Qualifiers - Assistant to the District Hero
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

n = int(input())
pts = []
for _ in range(n):
    x, y = map(int, input().split())
    pts.append((x, y))
    
pts.sort()

dp = [1] * n
for i in range(1, n):
    for j in range(i):
        if pts[j][0] <= pts[i][0] and pts[j][1] <= pts[i][1]:
            dp[i] = max(dp[i], 1 + dp[j])

print(max(dp))
