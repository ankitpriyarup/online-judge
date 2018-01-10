def main():
    n, k = map(int, input().split())
    if k == 1:
        print(n)
        return

    p = 1
    while (p << 1) <= n:
        p <<= 1

    print((p << 1) - 1)

main()
