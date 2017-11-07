def main():
    a = input()
    b = input()
    n = len(a)

    p1 = 0
    p2 = n - 1
    while p1 < p2 and a[p1] == b[p1]:
        p1 += 1
    while p1 < p2 and a[p2] == b[p2]:
        p2 -= 1

    chunk = ''.join(reversed(b[p1:p2 + 1]))
    # print(a[p1:p2 + 1])
    # print(chunk)
    if a[p1:p2 + 1] != chunk:
        print(0)
        return

    op1 = p1
    p1 -= 1
    p2 += 1
    while p1 >= 0 and p2 < n and a[p1] == a[p2]:
        p1 -= 1
        p2 += 1

    print(op1 - p1)

main()
