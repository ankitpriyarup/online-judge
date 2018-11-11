import sys

for line in sys.stdin:
    exp = line.strip()
    ans = float(eval(exp))
    print('{:.2f}'.format(ans))
