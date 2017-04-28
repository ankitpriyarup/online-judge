def main():
    s = input()
    a = 0
    b = len(s) - 1

    d = 0
    while a < b:
        if s[a] != s[b]:
            d += 1

        a += 1
        b -= 1

    safe = d == 1 or (d == 0 and len(s) % 2 == 1)
    print('YES' if safe else 'NO')


main()
