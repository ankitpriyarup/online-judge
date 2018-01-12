from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

# Turns out these aren't permutations (stupid label swaps...)
# Gonna do it the old fashioned way with cycle detection. Hopefully we find a cycle fast!

def main():
    seed = 'abcdefghijklmnop'
    arr = list(seed)
    inv = {c: i for i, c in enumerate(arr)}
    s = input().split(',')

    history = []
    for _ in range(int(1e9)):
        as_str = ''.join(arr)
        if as_str in history:
            start = history.index(as_str)
            cycle_len = len(history) - start
            ind = (int(1e9) % cycle_len) + start
            print(history[ind])
            return

        history.append(as_str)
        print(history)

        for cmd in s:
            if cmd[0] == 's':
                arg = int(cmd[1:])
                arr = arr[(16-arg):] + arr[:(16-arg)]
                inv = {c: i for i, c in enumerate(arr)}
            elif cmd[0] == 'x':
                a, b = map(int, cmd[1:].split('/'))
                arr[a], arr[b] = arr[b], arr[a]
                inv = {c: i for i, c in enumerate(arr)}
            else:
                x, y = cmd[1:].split('/')
                a, b = inv[x], inv[y]
                arr[a], arr[b] = arr[b], arr[a]
                inv = {c: i for i, c in enumerate(arr)}

    print(''.join(arr))

main()
