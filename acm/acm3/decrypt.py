def stringxor(a, b, x):
    # xor a with b starting at position x in a (use all of b)
    na = a
    for i in xrange(x, len(b) + x):
        if a[i] == b[i - x]:
            na = na[:i] + '0' + na[(i+1):]
        else:
            na = na[:i] + '1' + na[(i+1):]
    return na

def checksum(f, magic):
    q = f
    q += '0'*len(magic)
    for i in xrange(len(f)):
        if q[i] == '0':
            continue
        q = stringxor(q, magic, i)

    return q[-len(magic):]

T = int(raw_input())
for xx in xrange(T):
    N, C = map(int, raw_input().split())
    magic, correct = raw_input().split()
    f = raw_input()
    ans = -1

    for b in xrange(len(f)):
        nf = f[:b] + ('1' if f[b] == '0' else '0') + f[(b+1):]
        if checksum(nf, magic) == correct:
            ans = b
            break

    print ans
