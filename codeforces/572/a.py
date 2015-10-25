na, nb = map(int, raw_input().split())
k, m = map(int, raw_input().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())

print "YES" if a[k - 1] < b[-m] else "NO"
