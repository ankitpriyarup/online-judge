from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def main():
    state = 'A'
    steps = 12683008 
    tape = defaultdict(int)
    rules = { 'A': ((1,  1, 'B'), (0, -1, 'B')), 
              'B': ((1, -1, 'C'), (0,  1, 'E')),
              'C': ((1,  1, 'E'), (0, -1, 'D')),
              'D': ((1, -1, 'A'), (1, -1, 'A')),
              'E': ((0,  1, 'A'), (0,  1, 'F')),
              'F': ((1,  1, 'E'), (1,  1, 'A')) }

    pc = 0
    for _ in range(steps):
        val, dx, next_state = rules[state][tape[pc]]
        tape[pc] = val
        pc += dx
        state = next_state

    ck = sum(tape[x] for x in tape)
    print(ck)

main()
