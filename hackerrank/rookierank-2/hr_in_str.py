#!/bin/python3

import sys

target = "hackerrank"

q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    ptr = 0
    for c in s:
        if c == target[ptr]:
            ptr += 1
        if ptr == len(target):
            break
            
    print("YES" if ptr == len(target) else "NO")
