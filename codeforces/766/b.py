def main():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    works = False
    for i in range(2, n):
        if a[i - 2] + a[i - 1] > a[i]:
            works = True
            break

    print('YES' if works else 'NO')

main()
