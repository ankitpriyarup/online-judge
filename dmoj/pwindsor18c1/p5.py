dp = list(range(1001))
for i in range(2, 1001):
    dp[i] = max(i, max(dp[j] * dp[i - j] for j in range(1, i)))

print(dp[:50])
print(dp[int(input())] % int(1e9 + 7))
