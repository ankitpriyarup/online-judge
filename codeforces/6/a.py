def main():
    lens = list(map(int, input().split()))
    poss = False
    seg = False
    for i in range(4):
        for j in range(i + 1, 4):
            for k in range(j + 1, 4):
                a, b, c = sorted([lens[i], lens[j], lens[k]])
                if a + b > c:
                    poss = True
                if a + b == c:
                    seg = True

    if poss:
        print('TRIANGLE')
    elif seg:
        print('SEGMENT')
    else:
        print('IMPOSSIBLE')

main()
