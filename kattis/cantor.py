import math
import sys

ITER = 100

def is_cantor(num, den):
    for _ in range(ITER):
        if num == 0 or num == den:
            return True

        if den < 3 * num < 2 * den:
            return False

        if 3 * num <= den:
            num *= 3
        else:
            # n / d - 2 / 3
            # n - 2 d / 3 d
            num = 3 * num - 2 * den
            den *= 3

        g = math.gcd(num, den)
        num, den = num // g, den // g

    return True

def main():
    for line in sys.stdin:
        line = line.strip()
        if line == 'END':
            break

        num = 0
        den = 1
        in_frac = False

        for c in line:
            if c == '.':
                in_frac = True
            else:
                num *= 10
                num += int(c)
                if in_frac:
                    den *= 10

        print('MEMBER' if is_cantor(num, den) else 'NON-MEMBER')

main()
