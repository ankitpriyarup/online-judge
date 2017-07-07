def main():
    n = int(input())
    ans = 0

    while n % 2 == 0:
        ans += 1
        n //= 2

    for d in range(3, n, 2):
        if n == 1 or d * d > n:
            break

        while n % d == 0:
            ans += 1
            n //= d

    if n > 1:
        ans += 1

    print(ans)

main()
