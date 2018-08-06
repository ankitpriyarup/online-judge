def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    left = 0
    ans = 0
    while left < n and a[left] <= k:
        left += 1
        ans += 1
    right = n - 1
    while right >= 0 and a[right] <= k:
        right -= 1
        ans += 1

    print(min(ans, n))

main()
