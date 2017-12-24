def main():
    a, b, c = map(int, input().split())
    for op in '+-*':
        if eval(str(a) + op + str(b)) == c:
            return str(a) + op + str(b) + '=' + str(c)
        if eval(str(b) + op + str(c)) == a:
            return str(a) + '=' + str(b) + op + str(c)

    if a % b == 0 and a // b == c:
        return str(a) + '/' + str(b) + '=' + str(c)

    return str(a) + '=' + str(b) + '/' + str(c)

print(main())
