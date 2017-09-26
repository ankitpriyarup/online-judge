def main():
    a = int(input())
    # 180 - 360/n = a
    # 180n - 360 = an
    # n(180 - a) = 360
    # n = 360/(180-a)
    if 360 % (180 - a) == 0:
        print('YES')
    else:
        print('NO')

T = int(input())
for _ in range(T):
    main()
