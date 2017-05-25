def main():
    S = int(input())
    for _ in range(S):
        n = int(input())
        a = list(map(int, input().split()))
        if n % 2 == 0 or a[0] != 1 or a[-1] != 1:
            print('no')
            continue

        expected = [min(x, n + 1 - x) for x in range(1, n + 1)]
        print('yes' if a == expected else 'no')

main()
