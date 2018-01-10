from collections import *

def main():
    d = defaultdict(int)
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    c = 0
    ans = 0
    for x in a:
        ans += c * x - s
        for shift in range(-1, 2):
            y = x + shift
            ans -= d[y] * x - y * d[y]

        s += x
        c += 1
        d[x] += 1

    print(ans)

main()
