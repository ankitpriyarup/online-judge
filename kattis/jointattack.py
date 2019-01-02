from fractions import Fraction
import sys

n = int(sys.stdin.readline())
x = list(map(int, sys.stdin.readline().split()))

ans = Fraction(x[-1], 1)
for i in range(n - 2, -1, -1):
    ans = Fraction(x[i], 1) + Fraction(1, ans)

print('{}/{}'.format(ans.numerator, ans.denominator))
