from fractions import Fraction

"""
f = input()
(10^x a + b) f = 10 b + a
10^x a f + b f = 10 b + a
10^x a f - a = 10 b - b f
a (10^x f - 1) = b (10 - f)
a (10^x f - 1) / (10 - f) = b
"""
def main():
    f = Fraction(input())
    if f == 10:
        print('No solution')
        return
    printed = False
    res = []
    CAP = 100000000
    for a in range(1, 10):
        p = 1
        for l in range(9):
            b = a * (p * f - 1) / (10 - f)
            x = p * a + b
            if 0 <= b < p and 0 < x < CAP and b.denominator == 1 and f * x == 10 * b + a:
                res.append(x)

            p *= 10

    if res:
        res.sort()
        for x in res:
            print(x)
    else:
        print('No solution')

main()
