#!/usr/bin/env python3

def main():
    n, q = map(int, input().split())
    p = list(map(int, input().split()))
    for _ in range(q):
        k, a, b = map(int, input().split())
        if k == 1:
            a -= 1
            p[a] = b
        elif k == 2:
            a -= 1
            b -= 1
            print(abs(p[a] - p[b]))

main()
