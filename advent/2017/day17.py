from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

class Node(object):
    def __init__(self, x):
        self.prev = None
        self.next = None
        self.data = x

def main():
    # step = 3
    step = 356
    pos = 0
    total = 1

    for i in range(1, 50000001):
        pos = (pos + step) % total
        pos += 1
        if pos == 1:
            ans = i
        total += 1
        # buf = buf[:pos] + [i] + buf[pos:]

    print(ans)

main()
