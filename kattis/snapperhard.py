T = int(input())
tc = 1
for _ in range(T):
    n, k = map(int, input().split())
    total = (1 << n)
    ans = "ON" if (k + 1) % total == 0 else "OFF"
    print('Case #{}: {}'.format(tc, ans))
    tc += 1
