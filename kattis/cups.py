def is_int(x):
    return all(c in '0123456789' for c in x)

n = int(input())
cups = []
for _ in range(n):
    a, b = input().split()
    if is_int(a):
        cups.append((int(a), b))
    else:
        cups.append((2 * int(b), a))

cups.sort()
for _, name in cups:
    print(name)
