from collections import defaultdict
import sys

n = int(sys.stdin.readline())
a = list(int(x) for x in sys.stdin.readline().split())
ans = n
last = defaultdict(lambda: -n)
for i, x in enumerate(a):
    ans = min(ans, i - last[x])
    last[x] = i

print(ans)
