def main():
    a = list(map(int, input().split()))
    n = a[0]
    a = a[1:]
    b = []

    x = 2
    for _ in range(int(1.25e7)):
        x = x + 2

    for _ in range(n):
        ind = 0
        val = a[0]
        for i, x in enumerate(a):
            if x < val:
                ind = i
                val = x

        b.append(val)
        a = a[:ind] + a[(ind + 1):]

    print(' '.join(map(str, b)))

main()
