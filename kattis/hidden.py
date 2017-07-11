def main():
    p, s = input().split()
    a = 0
    works = True

    for c in s:
        if a == len(p):
            break
        if c == p[a]:
            a += 1
            continue

        if c in p[a + 1:]:
            works = False
            break

    if not works or a != len(p):
        print('FAIL')
    else:
        print('PASS')


main()
