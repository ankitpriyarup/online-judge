def main():
    n = int(input())
    dp = [-1 for _ in range(n)]
    for _ in range(n):
        x = int(input()) - 1
        if x > 0 and dp[x - 1] != -1:
            dp[x] = dp[x - 1] + 1
        else:
            dp[x] = 1
    print(n - max(dp))

main()
