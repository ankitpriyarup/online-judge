def main():
    blank = False
    while True:
        n = int(input())
        if n == 0:
            break

        names = []
        for _ in range(n):
            names.append(input())

        names.sort(key=lambda n: (n[:2]))

        if blank:
            print()

        for name in names:
            print(name)

        blank = True

main()
