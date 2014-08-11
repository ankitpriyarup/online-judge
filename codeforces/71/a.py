n = int(raw_input())
for i in xrange(n):
    s = raw_input()
    l = len(s)
    if l > 10:
        print s[0] + str(l - 2) + s[-1]
    else:
        print s
