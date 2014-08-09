n = int(raw_input())
b = []
for i in xrange(n):
    a = map(int, raw_input().split())
    b.append(a)
b.sort()
last = -1
happy = False
for e in b:
    if e[1] < last:
        happy = True
        break
    last = e[1]
if happy:
    print "Happy Alex"
else:
    print "Poor Alex"

