def main():
    n = int(input())

    p1, p2 = [], []

    last = 1
    for _ in range(n):
        move = int(input())

        if move > 0:
            p1.append(move)
            last = 1
        else:
            p2.append(-move)
            last = 2

    if sum(p1) != sum(p2):
        print('first' if sum(p1) > sum(p2) else 'second')
    elif p1 != p2:
        print('first' if p1 > p2 else 'second')
    else:
        print('first' if last == 1 else 'second')

main()
