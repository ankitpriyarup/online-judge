from fractions import Fraction

s, t = input().split()
n = len(s)
t = int(t)
tot_after_dec = n - 1 - s.index('.')
a = s[:n-t]
b = s[n-t:]
m = len(a)
x = a.index('.')
den = pow(10, m - 1 - x)
a = a.replace('.', '')
f1 = Fraction(int(a), den)
f2 = Fraction(int(b), pow(10, tot_after_dec - t) * (pow(10, t) - 1))
ans = f1 + f2
print('{}/{}'.format(ans.numerator, ans.denominator))
