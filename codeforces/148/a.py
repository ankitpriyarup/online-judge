from collections import *
import sys

def main():
    a = []
    for _ in range(4):
        a.append(int(input()))

    d = int(input())
    ans = 0
    for x in range(1, d + 1):
        hurt = any(x % i == 0 for i in a)
        if hurt:
            ans += 1

    print(ans)

main()
