def custom(s1, s2):
    if s1[2] == s2[2]:
        if s1[1] == s2[1]:
            return -1 if s1[0] < s2[0] else 1
        return -1 if s1[1] < s2[1] else 1
    else:
        return -1 if s1[2] < s2[2] else 1

T = int(raw_input())
for xx in xrange(T):
    N = int(raw_input())
    soldiers = []
    for s in xrange(N):
        f, l, h = raw_input().split()
        soldiers.append([f, l, h])

    print "Test Case #" + str(xx + 1) + ":"
    for soldier in sorted(soldiers, custom):
        print soldier[0], soldier[1]
