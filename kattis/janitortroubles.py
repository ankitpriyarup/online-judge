from math import sqrt
from functools import reduce
a = list(map(int, input().split()))
s = sum(a) / 2.0
ans = sqrt(reduce(lambda x, y: x * y, [(s - x) for x in a]))
print('{:.10f}'.format(ans))
