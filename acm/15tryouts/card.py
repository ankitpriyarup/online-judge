T = int(raw_input())
for case in range(1, T + 1):
    card, exp = raw_input().split()
    if len(card) == 8 and int(card[0]) % 2 == 1 and 1 <= int(exp[0:2]) <= 12 and int(card) % int(exp) == 0:
        print "Case %d: VALID" % case
    else:
        print "Case %d: BOGUS" % case
