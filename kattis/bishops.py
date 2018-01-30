import sys
for line in sys.stdin:
    x = int(line.strip())
    if x == 1:
        print(1)
    else:
        print(2 * x - 2)
