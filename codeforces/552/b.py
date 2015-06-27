def less(n):
    ret = 1
    while ret <= n:
        ret *= 10
    return ret / 10

n = raw_input()
l = len(n)
n = int(n)
#print n, l

ans = 0
lower = 9
for i in xrange(1, l):
    ans += lower * i
    lower *= 10

#print ans
if n >= 10:
    #print n, less(n)
    ans += (n - less(n) + 1) * l
else:
    ans = int(n)

print ans
