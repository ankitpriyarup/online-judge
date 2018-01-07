while True:
    l = list(map(int, input().split()))
    if all(x == 0 for x in l):
        break

    l.sort()
    if l[0] * l[0] + l[1] * l[1] == l[2] * l[2]:
        print('right')
    else:
        print('wrong')

