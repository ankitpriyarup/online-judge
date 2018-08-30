import sys

def score(a, b):
    if (a, b) in [(1, 2), (2, 1)]:
        return 1000
    elif a == b:
        return 100 * a
    else:
        if a < b:
            a, b = b, a
        return 10 * a + b

for line in sys.stdin:
    a, b, c, d = map(int, line.strip().split())
    if a == 0:
        break

    sx = score(a, b)
    sy = score(c, d)
    if sx == sy:
        print('Tie.')
    elif sx > sy:
        print('Player 1 wins.')
    else:
        print('Player 2 wins.')
