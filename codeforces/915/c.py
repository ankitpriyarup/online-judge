from collections import Counter

def can_make(c, b, l):
    d = Counter(c)
    for i in range(l):
        if d[b[i]] == 0:
            return False
        d[b[i]] -= 1

    res = int(b[l])
    for x in range(res - 1, -1, -1):
        if d[str(x)] > 0:
            return True

    return False

def main():
    a = input()
    b = input()
    if len(a) < len(b):
        a = list(a)
        a.sort(reverse=True)
        print(''.join(a))
        return

    c = Counter(a)
    if c == Counter(b):
        print(b)
        return

    for i in range(len(b) - 1, -1, -1):
        if can_make(c, b, i):
            res = i
            break

    out = []
    for i in range(res):
        out.append(b[i])
        c[b[i]] -= 1

    x = int(b[res])
    for y in range(x - 1, -1, -1):
        sy = str(y)
        if c[sy] > 0:
            out.append(sy)
            c[sy] -= 1
            break

    for y in range(9, -1, -1):
        sy = str(y)
        out += [sy] * c[sy]

    print(''.join(out))

main()
