def sumdigits(n):
    if n < 10:
        return n
    return sumdigits(n / 10) + (n % 10)

a, b, c = map(int, raw_input().split())
#s(x) ranges from 0 to 81
#s(x)^5 ranges from 0 to 3486784401

out = []
for s in xrange(82):
    ans = b*(pow(s, a)) + c
    if sumdigits(ans) == s:
        out.append(ans)

#out = [x for x in out if 0 < x < 1000000000]

print len(out)
if len(out) > 0:
    print ' '.join(map(str, out))
