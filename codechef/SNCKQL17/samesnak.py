def same_same(a, b, c, d):
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c

    return (a <= c <= b) or (c <= a <= d)

def main():
    x11, y11, x12, y12 = map(int, input().split())
    x21, y21, x22, y22 = map(int, input().split())

    same = False
    if x11 == x12 and x21 == x22:
        same = same_same(y11, y12, y21, y22)
    elif y11 == y12 and y21 == y22:
        same = same_same(x11, x12, x21, x22)
    else:
        orig = [(x11, y11), (x12, y12), (x21, y21), (x22, y22)]
        target = 4
        if orig[0] == orig[1]:
            target -= 1
        if orig[2] == orig[3]:
            target -= 1

        same = len(set(orig)) < target

    print('yes' if same else 'no')

T = int(input())
for _ in range(T):
    main()
