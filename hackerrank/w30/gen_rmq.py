from random import randint

def main():
    n = 40000
    maxn = 40000
    q = 40000
    print(n, q)
    a = [randint(1, maxn) for _ in range(n)]
    print(' '.join(str(x) for x in a))

    for _ in range(q):
        small_range = randint(0, 1)
        l = randint(0, n // 2)
        if small_range == 1:
            r = randint(l + 1, l + 150)
        else:
            r = randint(n // 2, n - 1)

        small_x = randint(0, 1)
        if small_x == 1:
            x = randint(1, 100)
        else:
            x = randint(1, maxn // 3)

        y = randint(0, x - 1)

        print(l, r, x, y)

main()
