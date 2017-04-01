def main():
    n = int(input())
    small_less = int(2e9) + 1
    big_great = int(-2e9) - 1

    flip = {'>': '<', '<': '>'}

    for _ in range(n):
        kind, num, ans = input().split()
        num = int(num)
        if ans == 'N':
            had_eq = len(kind) == 2
            kind = flip[kind[0]]
            if not had_eq:
                kind += '='

        if kind == '<=':
            kind = '<'
            num += 1
        elif kind == '>=':
            kind = '>'
            num -= 1

        if kind == '<':
            small_less = min(small_less, num)
        else:
            big_great = max(big_great, num)

    if small_less - 1 <= big_great:
        print('Impossible')
    else:
        print(small_less - 1)


main()
