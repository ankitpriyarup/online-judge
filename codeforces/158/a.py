n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
a = list(reversed(sorted(a)))
cutoff = a[k-1]
print len([x for x in a if x > 0 and x >= cutoff])
