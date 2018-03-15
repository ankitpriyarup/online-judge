import math
from fractions import Fraction

n, q = map(int, input().split())
therms = []
for _ in range(n):
    a, b = map(int, input().split())
    therms.append((a, b))

for _ in range(q):
    a, b, v = map(int, input().split())
    # convert v from unit a to celsius
    # v / (b - a) = x / 100
    a -= 1
    b -= 1
    cels = Fraction(100, 1) * Fraction(v - therms[a][0], therms[a][1] - therms[a][0])

    # convert cels to unit b
    # x / 100 = y / (b - a)
    ans = therms[b][0] + Fraction(therms[b][1] - therms[b][0], 100) * cels
    g = math.gcd(ans.numerator, ans.denominator)
    print('{}/{}'.format(ans.numerator // g, ans.denominator // g))
