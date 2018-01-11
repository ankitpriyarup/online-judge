def main():
    a, b = map(int, input().split())
    m = min(a, b)
    ans = 1
    for i in range(2, m + 1):
        ans *= i

    print(ans)

main()
