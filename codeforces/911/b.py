def main():
    n, a, b = map(int, input().split())
    ans = min(a // n, b // n)
    for x in range(1, n):
        y = n - x
        ans = max(ans, min(a // x, b // y))

    print(ans)

main()
