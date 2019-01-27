from collections import Counter
MOD = 998244353
n, k = map(int, input().split())
a = Counter(map(int, input().split())).most_common()
dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
dp[0][0] = 1

m = len(a)
for i in range(m):
    for j in range(n):
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= MOD

        dp[i + 1][j + 1] += dp[i][j] * a[i][1] % MOD
        dp[i + 1][j + 1] %= MOD

print(dp[m][k])
