def min_base(s):
    score = {str(x): x for x in range(10)}
    for c in range(26):
        score[chr(c + ord('a'))] = c + 10

    return 1 + max(score[c] for c in s)

def works(base, a, op, b, c):
    if base == 1:
        if not all(all(c == '1' for c in x) for x in (a, b, c)):
            return False

        x = len(a)
        y = len(b)
        z = len(c)
    else:
        x = int(a, base)
        y = int(b, base)
        z = int(c, base)

    if op == '+':
        return x + y == z
    elif op == '-':
        return x - y == z
    elif op == '*':
        return x * y == z
    elif op == '/':
        return (y != 0) and (x % y == 0) and (x // y == z)

def main():
    eqn = input().split()
    a, op, b, c = eqn[0], eqn[1], eqn[2], eqn[4]
    start_base = max(min_base(x) for x in (a, b, c))

    out = []
    if works(1, a, op, b, c):
        out.append(1)
    for base in range(start_base, 37):
        if works(base, a, op, b, c):
            out.append(base)

    if not out:
        print('invalid')
    else:
        show = {x: str(x) for x in range(10)}
        for c in range(26):
            show[c + 10] = chr(c + ord('a'))
        show[36] = '0'

        print(''.join(show[v] for v in out))

T = int(input())
for _ in range(T):
    main()
