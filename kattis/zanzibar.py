T = int(input())
for _ in range(T):
    a = list(map(int, input().split()))
    a = a[1:-1]
    last = 1
    ans = 0
    for x in a:
        ans += max(0, x - 2 * last)
        last = x
    print(ans)
