n = int(raw_input())
minx = 1e9 + 1
miny = 1e9 + 1
maxx = -minx
maxy = -miny
for x in xrange(n):
    x, y = map(int, raw_input().split())
    minx = min(minx, x)
    miny = min(miny, y)
    maxx = max(maxx, x)
    maxy = max(maxy, y)

maxlen = max((maxx - minx), (maxy - miny))
print maxlen * maxlen
