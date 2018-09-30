from fractions import Fraction

T = int(input())
for _ in range(T):
    a, b, c = map(Fraction, input().split())
    res = a + b + c
    print('{}/{}'.format(res.numerator, res.denominator))
