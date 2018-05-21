def main():
    s = input()
    n = int(input())
    a = eval(input())
    rev = False
    p1 = 0
    p2 = n - 1
    error = False
    for c in s:
        if c == 'R':
            rev = not rev
        else:
            if not rev:
                p1 += 1
            else:
                p2 -= 1

            if p1 > p2 + 1:
                error = True
                break

    if error:
        print('error')
    else:
        ans = a[p1:p2+1]
        if rev:
            print('[{}]'.format(','.join(str(x) for x in reversed(ans))))
        else:
            print('[{}]'.format(','.join(str(x) for x in ans)))

T = int(input())
for _ in range(T):
    main()
