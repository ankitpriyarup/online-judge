def main():
    s, e = input().split()
    s = s[2:-1]
    e = e[:-1]

    l = len(s)

    for c in s:
        print('(c{}r '.format(c),end='')
    print(e,end='')
    print(')' * l)


main()
