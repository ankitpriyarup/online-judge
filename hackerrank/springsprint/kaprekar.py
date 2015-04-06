squares = map(str, [i * i for i in xrange(100001)])
def kaprekar(n):
    s = squares[n]
    d = len(s) / 2

    left = 0 if len(s[:d]) < 1 else int(s[:d])
    right = 0 if len(s[d:]) < 1 else int(s[d:])

    return n == left + right

p = int(raw_input())
q = int(raw_input())

ans = []
for i in xrange(p, q + 1):
    if kaprekar(i):
        ans.append(i)

if len(ans) > 0:
    print ' '.join(map(str, ans))
else:
    print 'INVALID RANGE'
