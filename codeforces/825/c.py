def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    b = k
    p = 0
    ans = 0
    while p < n:
        while 2 * b < a[p]:
            b = 2 * b
            ans += 1

        b = max(b, a[p])
        p += 1

    print(ans)

main()
