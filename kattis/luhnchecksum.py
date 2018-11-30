T = int(input())
for _ in range(T):
    s = input()
    n = len(s)
    ans = 0
    for i in range(-1, -n - 1, -1):
        if i % 2 == 0:
            v = 2 * int(s[i])
            if v >= 10:
                v = (v // 10) + (v % 10)
        else:
            v = int(s[i])
        ans += v
    print('PASS' if ans % 10 == 0 else 'FAIL')
