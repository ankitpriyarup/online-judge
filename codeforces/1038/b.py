def main():
    n = int(input())
    tot = n * (n + 1) // 2
    for x in range(2, n + 1):
        if tot % x == 0:
            print('Yes')
            print('1 {}'.format(x))
            o = [y for y in range(1, n + 1) if y != x]
            print('{} {}'.format(len(o), ' '.join(str(x) for x in o)))
            return
    print('No')

main()
