import math

G = 9.8
T = int(raw_input())
for xx in xrange(T):
    D, M = map(float, raw_input().split())
    if M*M / G < D:
        print "Impossible"
    else:
        print "{0:.3f}".format(math.degrees(math.asin(D*G/(M*M))) / 2.0)
