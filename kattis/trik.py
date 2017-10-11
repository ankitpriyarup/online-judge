def main():
    s = input()
    p = 1

    for c in s:
        if c == 'A':
            if p <= 2:
                p = 3 - p
        elif c == 'B':
            if p >= 2:
                p = 5 - p
        else:
            if p != 2:
                p = 4 - p

    print(p)

main()
