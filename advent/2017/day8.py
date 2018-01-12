from collections import *
import itertools
import random
import sys

def main():
    d = defaultdict(int)
    ans = -19
    for line in sys.stdin:
        words = line.strip().split()
        d_reg = words[0]
        sgn = 1 if words[1] == 'inc' else -1
        amt = int(words[2])

        reg = words[4]
        e = words[5]
        amt2 = int(words[6])

        val = d[reg]
        if eval(str(val) + ' ' + e + ' ' + str(amt2)):
            d[d_reg] += sgn * amt

        # ans = max(ans, (max(v for k, v in d.items())))

    print(max(v for k, v in d.items()))

main()
