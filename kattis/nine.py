mod = 1000000007
T = int(input())
for _ in range(T):
    n = int(input())
    ans = 8 * pow(9, n - 1, mod) % mod
    print(ans)
