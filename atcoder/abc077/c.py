import bisect

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    a.sort()
    b.sort()
    c.sort()
    ans = 0
    for y in b:
        i = bisect.bisect_left(a, y)
        j = bisect.bisect_right(c, y)
        if i > 0 and j != len(c):
            ans += i * (n - j)

    print(ans)

main()
