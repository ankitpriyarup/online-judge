from collections import Counter

s = input()
d = Counter([(0, 0)])
x, y = 0, 0
x2, y2 = 0, 0
for i, c in enumerate(s):
    if i % 2 == 0:
        if c == '^':
            x -= 1
        elif c == '>':
            y += 1
        elif c == 'v':
            x += 1
        else:
            y -= 1

        d[(x, y)] += 1
    else:
        if c == '^':
            x2 -= 1
        elif c == '>':
            y2 += 1
        elif c == 'v':
            x2 += 1
        else:
            y2 -= 1

        d[(x2, y2)] += 1


print(d)
print(len(d))

