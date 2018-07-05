def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    top = max(a)
    tot = sum(a)
    occ = 0
    ans = -1
    for i, x in enumerate(a):
        if x == top:
            occ += 1
            ans = i + 1

    if occ > 1:
        print('no winner')
    elif 2 * top > tot:
        print('majority winner {}'.format(ans))
    else:
        print('minority winner {}'.format(ans))

T = int(input())
for _ in range(T):
    main()
