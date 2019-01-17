a = input()
b = input()
c = ''.join(sorted(a))
if c[0] == '0':
    p = 0
    while p < len(c) and c[p] == '0':
        p += 1
    if p < len(c):
        c = list(c)
        c[0], c[p] = c[p], c[0]
        c = ''.join(c)

print('OK' if b == c else 'WRONG_ANSWER')

