from fractions import Fraction
def main():
    a, b = map(int, input().split('/'))
    f = Fraction(a, b)
    res = Fraction(5, 9) * (f - Fraction(32, 1))
    print('{}/{}'.format(res.numerator, res.denominator))

main()
