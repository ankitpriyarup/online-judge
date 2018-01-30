T = int(input())
tc = 1
for _ in range(T):
    n = int(input())
    a = map(int, input().split())
    res = 0
    for x in a:
        res ^= x
    print('Case #{}: {}'.format(tc, res))
    tc += 1
