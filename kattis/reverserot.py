import sys

s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_.'

for line in sys.stdin:
    nw = line.strip()
    if nw == '0':
        break

    n, w = nw.split()
    n = int(n)
    t = s[n:] + s[:n]
    c = dict((x, y) for x, y in zip(s, t))
    o = ''.join(c[x] for x in reversed(w))
    print(o)
