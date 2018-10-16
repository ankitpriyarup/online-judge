a, b = input().split()
if a == 'D':
    o = []
    for i in range(0, len(b), 2):
        for j in range(int(b[i + 1])):
            o.append(b[i])
    print(''.join(o))
else:
    o = []
    last = ''
    ct = 0
    for c in b:
        if c == last:
            ct += 1
        else:
            if ct > 0:
                o.append(last)
                o.append(str(ct))
            ct = 1
            last = c
    o.append(last)
    o.append(str(ct))
    print(''.join(o))
