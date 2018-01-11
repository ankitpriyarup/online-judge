def main():
    n = int(input())
    a = list(map(int, input().split()))

    ans = max(sum(a), n - sum(a))
    for i in range(n):
        ans = max(ans, sum(a[i:]) + i - sum(a[:i]))

    print(ans)

main()
