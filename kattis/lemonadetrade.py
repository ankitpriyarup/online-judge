from collections import defaultdict
from fractions import Fraction
import math

def main():
    n = int(input())
    of_kind = {}
    of_kind['pink'] = 0.0
    for _ in range(n):
        dst, src, ratio = input().split()
        ratio = math.log(float(ratio))
        # print(ratio)

        if src in of_kind:
            of_kind[dst] = max(of_kind.get(dst, -10000000.0), ratio + of_kind[src])
        # print(of_kind)

    if 'blue' not in of_kind:
        print('0.00000000000000000')
    else:
        ans = min(math.log(10.0), of_kind['blue'])
        print('{:.13f}'.format(math.exp(ans)))

main()
