from math import ceil

T = int(raw_input())

for tc in xrange(1, T + 1):
    D = int(raw_input())
    P = map(int, raw_input().split())
    pmax = max(P)
    ans = pmax

    for h in xrange(1, pmax + 1):
        special = 0
        for stack in P:
            special += ceil(float(stack) / h) - 1

        ans = min(ans, special + h)

    print 'Case #%d: %d' % (tc, ans)
