from collections import defaultdict

def main():
    n = int(input())
    if n < 26:
        print('impossible')
        return
    elif n > 26:
        print('possible')
        return

    by_suit = defaultdict(list)
    for _ in range(n):
        a, b = input().split()
        a = int(a)
        by_suit[b].append(a)

    win = False
    for suit in 'CDHS':
        by_suit[suit].sort()
        for i in range(2, 14):
            if i not in by_suit[suit]:
                continue

            for j in range(1, i):
                if j not in by_suit[suit]:
                    win = True
                    break

    if win:
        print('possible')
    else:
        print('impossible')


main()
