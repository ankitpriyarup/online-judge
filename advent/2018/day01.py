from collections import *
import itertools
import random
import sys

def main():
    ans = 0
    seen = set([0])
    freqs = []
    for line in sys.stdin:
        x = int(line.strip())
        freqs.append(x)

    p = 0
    while True:
        ans += freqs[p]
        p = (p + 1) % len(freqs)
        if ans in seen:
            print(ans)
            break
        seen.add(ans)

    print(ans)

main()
