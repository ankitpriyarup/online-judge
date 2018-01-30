def main():
    n = int(input())
    a, b = 1, 1
    out = []
    for i in range(1, n + 1):
        while b < i:
            a, b = b, a + b

        if b == i:
            out.append('O')
        else:
            out.append('o')

    print(''.join(out))

main()
