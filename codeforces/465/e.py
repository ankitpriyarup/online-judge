s = raw_input()
n = int(raw_input())
for i in xrange(n):
    inn, out = raw_input().split('->')
    s = s.replace(inn, out)

if len(s) == 0:
    s = '0'
print int(s, 10) % 1000000007
