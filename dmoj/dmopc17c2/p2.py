def main():
    s = input()
    imba = 0
    min_pref = 0
    for i, c in enumerate(s):
        if c == '(':
            imba += 1
        else:
            imba -= 1
        min_pref = min(min_pref, imba)

    # print(imba, min_pref)
    if abs(imba) > 2:
        print('NO')
        return
    if imba >= 0 and min_pref < 0:
        print('NO')
        return
    if imba == -2 and min_pref < -2:
        print('NO')
        return

    print('YES')

main()
