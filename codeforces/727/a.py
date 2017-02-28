def main():
    a, b = map(int, input().split())

    path = [b]
    while b > 0 and b != a:
        if b % 10 == 1:
            b //= 10
        elif b % 2 == 0:
            b //= 2
        else:
            path = None
            break

        path.append(b)

    if not path or path[-1] != a:
        print('NO')
    else:
        print('YES')
        print(len(path))
        print(' '.join([str(x) for x in reversed(path)]))


main()
