def main():
    n, m = map(int, input().split())
    a = input()
    b = input()

    prev = range(m + 1)
    dp = [0 for _ in range(m + 1)]

    for i in range(1, n + 1):
        dp[0] = i
        for j in range(1, m + 1):
            dp[j] = prev[j - 1]
            if a[i - 1] != b[j - 1]:
                dp[j] += 1

            dp[j] = min(dp[j], prev[j] + 1)
            dp[j] = min(dp[j], dp[j - 1] + 1)

        prev = dp
        dp = [0 for _ in range(m + 1)]

    ans = 0
    for i in range(1, m):
        ans += prev[i]

    print(ans)

main()
