def main():
    h1, a1, c = map(int, input().split())
    h2, a2 = map(int, input().split())

    out = []

    while h2 > 0:
        if a2 < h1 or a1 >= h2:
            out.append('STRIKE')
            h2 -= a1
            h1 -= a2
        else:
            out.append('HEAL')
            h1 += c
            h1 -= a2

    print(len(out))
    for s in out:
        print(s)


main()
