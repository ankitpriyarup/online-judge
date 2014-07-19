sqlist = [i*i for i in xrange(1, 200000)]
sqset = set(sqlist)

T = int(raw_input())
for ll in xrange(1, T+1):
    K = int(raw_input())
    ans = -1
    for sq in sqlist:
        N = sq - K
        if N > 0 and N % 2 == 0 and (N/2 + K) in sqset:
            ans = N
            break
    print "Case %d: %d" % (ll, ans)

