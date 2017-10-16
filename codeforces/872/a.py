def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(1, 10):
        if i in a and i in b:
            print(i)
            return

    for i in range(1, 10):
        for j in range(1, 10):
            if (i in a and j in b) or (i in b and j in a):
                print(''.join(str(x) for x in (i, j)))
                return

main()
