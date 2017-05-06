def main():
    a, b, c = map(int, input().split())

    seen = set()
    ans = 0
    while all(x % 2 == 0 for x in (a, b, c)):
        if (a, b, c) in seen:
            ans = -1
            break

        seen.add((a, b, c))
        a, b, c = b // 2 + c // 2, a // 2 + c // 2, a // 2 + b // 2
        ans += 1

    print(ans)

main()
