a = sum(map(int, raw_input().split()))
b = sum(map(int, raw_input().split()))
n = int(raw_input())

for i in xrange(n):
    if a > 0:
        a -= 5
    else:
        b -= 10

if a <= 0 and b <= 0:
    print "YES"
else:
    print "NO"
