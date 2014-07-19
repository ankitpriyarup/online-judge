import sys

while True:
    line = map(int, raw_input().split())
    if line[0] == 0:
        sys.exit(0)
    line = line[1:]
    sambreak = -1
    for i in xrange(1, len(line)):
        sam = line[:i]
        em = line[i:]
        if sum(sam) == sum(em):
            sambreak = len(sam)
            break
    if sambreak == -1:
        print "No equal partitioning."
    else:
        print "Sam stops at position %d and Ella stops at position %d." % (sambreak, sambreak+1)


