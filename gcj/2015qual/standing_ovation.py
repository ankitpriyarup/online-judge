T = int(raw_input())

for case_num in xrange(1, T + 1):
    S = raw_input().split()[1]
    ans = 0
    standing = 0
    for i, c in enumerate(S):
        count = int(c)
        if count == 0:
            continue

        if standing < i:
            ans += (i - standing)
            standing += (i - standing)

        standing += count

    print 'Case #%d: %d' % (case_num, ans)
