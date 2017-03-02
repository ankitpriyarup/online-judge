def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))

    ans = 0
    for _ in range(m):
        l, r = map(int, input().split())
        l -= 1
        r -= 1

        seg_sum = sum(a[l:(r + 1)])
        ans += max(0, seg_sum)

    print(ans)

main()
