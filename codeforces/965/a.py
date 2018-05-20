def main():
    k, n, s, p = map(int, input().split())
    sheets = (n + s - 1) // s
    packs = (sheets * k + p - 1) // p
    print(packs)

main()
