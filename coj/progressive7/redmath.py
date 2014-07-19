import sys
while True:
    d, k = map(int, raw_input().split())
    if d == 0 and k == 0:
        sys.exit(0)
    n = int(str(d)*k)
    n = n*n
    print sum(map(int, str(n)))

