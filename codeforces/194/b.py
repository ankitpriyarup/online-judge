def main():
    T = int(input())
    a = map(int, input().split())
    for n in a:
        for opt in (n, 2 * n, 4 * n):
            if opt * (n + 1) % (4 * n) == 0:
                print(opt + 1)
                break

main()
