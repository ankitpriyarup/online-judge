from collections import *
import itertools
import random
import sys

def main():
    s = 0
    for line in sys.stdin:
        a = list(map(int, line.strip().split()))
        for i in range(len(a)):
            for j in range(len(a)):
                if i != j and a[i] % a[j] == 0:
                    s += a[i] // a[j]
    print(s)

main()
