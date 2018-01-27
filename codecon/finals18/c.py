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
    n = int(input())
    prog = []
    for _ in range(n):
        prog.append(tuple(input().strip().split()))

    pc = 0
    while 0 <= pc < len(prog):
        #print(pc, prog[pc])
        #print(regs)
        if len(prog[pc]) == 3:
            a, b, c = prog[pc]
            jmp = False
            if a == 'set':
                regs[b] = get(regs, c)
            elif a == 'add':
                regs[b] += get(regs, c)
            elif a == 'sub':
                regs[b] -= get(regs, c)
            elif a == 'mul':
                regs[b] *= get(regs, c)
            elif a == 'div':
                regs[b] //= get(regs, c)
            elif a == 'mod':
                regs[b] %= get(regs, c)
        else:
            a, b = prog[pc]
            if a == 'jmp':
                delta = get(regs, b)
                pc += delta
                pc -= 1
                if delta == 0:
                    pc += 1
            elif a == 'ret':
                print(regs[b])
                pc = len(prog)

        pc += 1

main()
