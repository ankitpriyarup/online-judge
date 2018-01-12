from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

def get(regs, x):
    if x in 'abcdefgh':
        return regs[x]
    return int(x)

def main():
    regs = {c: 0 for c in 'abcdefgh'}
    regs['a'] = 1
    prog = []
    for line in sys.stdin:
        a, b, c = line.strip().split()
        prog.append((a, b, c))

    pc = 0
    while 0 <= pc < len(prog):
        a, b, c = prog[pc]
        jmp = False
        if a == 'set':
            regs[b] = get(regs, c)
        elif a == 'sub':
            regs[b] -= get(regs, c)
        elif a == 'mul':
            regs[b] *= get(regs, c)
        else:
            if get(regs, b) != 0:
                jmp = True
                pc += get(regs, c)

        if pc == 18:
            regs['e'] = 109299

        if pc == 20:
            print('BROKE')

        if not jmp:
            pc += 1

        print(pc, regs)

main()
