def main():
    n = int(input())
    poss = False
    for i in range(100):
        if 3 * i > n:
            break
        if (n - 3 * i) % 7 == 0:
            poss = True
            break

    print('YES' if poss else 'NO')

T = int(input())
for _ in range(T):
    main()
