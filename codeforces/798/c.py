from math import gcd
from functools import reduce

def main():
    n = int(input())
    a = list(map(int, input().split()))

    print('YES')
    if reduce(gcd, a) > 1:
        print(0)
    else:
        ans = 0
        for i in range(n - 1):
            while a[i] % 2 != 0:
                a[i], a[i + 1] = a[i] - a[i + 1], a[i] + a[i + 1]
                ans += 1

        while a[-1] % 2 != 0:
            a[-2], a[-1] = a[-2] - a[-1], a[-2] + a[-1]
            ans += 1

        print(ans)

main()
