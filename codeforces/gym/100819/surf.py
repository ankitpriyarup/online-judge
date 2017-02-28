def search(arr, start, target):
    if arr[start + 1][0] >= target:
        return start + 1

    if arr[-1][0] < target:
        return -1

    lo = start + 1
    hi = len(arr) - 1

    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if arr[mid][0] >= target:
            hi = mid
        else:
            lo = mid

    return hi

def main():
    n = int(input())
    waves = []
    for _ in range(n):
        m, f, w = map(int, input().split())
        waves.append((m, f, w))

    waves.sort(key=lambda x: x[0])

    dp = [-1] * n

    dp[-1] = waves[-1][1]

    for i in range(n - 2, -1, -1):
        dp[i] = dp[i + 1]
        m, f, w = waves[i]
        next_ind = search(waves, i, m + w)

        if next_ind == -1:
            dp[i] = max(dp[i], f)
        else:
            dp[i] = max(dp[i], f + dp[next_ind])

    print(max(dp))

main()
