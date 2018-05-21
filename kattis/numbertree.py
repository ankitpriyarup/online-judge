def main():
    hp = input().split()
    h = int(hp[0])
    tot = (1 << (h + 1))
    pos = 1
    if len(hp) > 1:
        for c in hp[1]:
            if c == 'L':
                pos = 2 * pos
            else:
                pos = 2 * pos + 1

    print(tot - pos)

main()
