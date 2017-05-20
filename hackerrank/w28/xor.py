#!/bin/python3

q = int(input().strip())
for _ in range(q):
    n = int(input().strip())
    p = 1
    ans = 0
    
    while p <= n:
        if n & p == 0:
            ans |= p

        p <<= 1
        
    print(ans)

