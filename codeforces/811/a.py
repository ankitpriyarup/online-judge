def main():
    v = list(map(int, input().split()))
    x = 1
    while True:
        i = 1 - (x % 2)
        v[i] -= x
        if v[i] < 0:
            break

        x += 1

    print('Vladik' if x % 2 == 1 else 'Valera')

main()
