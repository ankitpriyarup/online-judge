import sys

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break

    n -= 1
    if n == 0:
        print('{ }')
        continue

    pows = [1]
    for i in range(1, 65):
        pows.append(pows[-1] * 3)

    v = []
    for i in range(64):
        b = (1 << i)
        if b > n:
            break
        if (n & b) > 0:
            v.append(pows[i])

    print('{', ', '.join(str(x) for x in v), '}')
