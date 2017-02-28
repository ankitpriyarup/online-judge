def main():
    n, k = map(int, input().split())
    c = 1
    while k % 2 == 0:
        k /= 2
        c += 1
    print(c)

main()
