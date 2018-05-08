a, b, k = map(int, input().split())
dp = [[1]]
for i in range(1, k + 1):
    row = [1]
    for j in range(1, i):
        row.append(dp[i - 1][j - 1] + dp[i - 1][j])
    row.append(1)
    dp.append(row)

ans = 0
for exp in range(k + 1):
    ans += dp[k][exp] * pow(a, exp) * pow(b, k - exp)

print(ans)
