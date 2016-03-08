def alt(a, b, c, d):
    if d == 8 or a == []:
        return c
    return alt(b, a[:-1], c + a[-1], d + 1)
    

inp = raw_input().split()

odd = []
even = []
for i in xrange(0, len(inp), 2):
    char = inp[i]
    val = int(inp[i + 1])
    if val % 2 == 0:
        even.append(val)
    else:
        odd.append(val)

odd.sort()
even.sort()

print alt(odd, even, 0, 0)
