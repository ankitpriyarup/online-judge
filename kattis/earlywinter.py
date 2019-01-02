import sys

n, dm = map(int, sys.stdin.readline().split())
d = list(map(int, sys.stdin.readline().split()))
for i in range(n):
    if d[i] <= dm:
        print('It hadn\'t snowed this early in {} years!'.format(i))
        break
else:
    print('It had never snowed this early!')

