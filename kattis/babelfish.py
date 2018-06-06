import sys
d = {}
for line in sys.stdin:
    line = line.strip()
    if not line:
        break
    x, y = line.split()
    d[y] = x

for line in sys.stdin:
    print(d.get(line.strip(), 'eh'))
