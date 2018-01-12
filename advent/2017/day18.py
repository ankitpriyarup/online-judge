from collections import *
from functools import reduce
import copy
import itertools
import random
import sys

q = [deque([]) for _ in range(2)]
ans = 0

class Prog(object):
    def __init__(self, prog, proc):
        self.prog = prog
        self.proc = proc
        self.pc = 0
        self.regs = defaultdict(int)
        self.regs['p'] = proc
        self.sent = 0

    def get(self, x):
        try:
            v = int(x)
            return v
        except:
            return self.regs[x]

    def step(self):
        if not (0 <= self.pc < len(self.prog)):
            return False

        cmd = self.prog[self.pc]
        jmp = False
        if cmd[0] == 'snd':
            self.sent += 1
            q[1 - self.proc].append(self.get(cmd[1]))
        elif cmd[0] == 'set':
            self.regs[cmd[1]] = self.get(cmd[2])
        elif cmd[0] == 'add':
            self.regs[cmd[1]] += self.get(cmd[2])
        elif cmd[0] == 'mul':
            self.regs[cmd[1]] *= self.get(cmd[2])
        elif cmd[0] == 'mod':
            self.regs[cmd[1]] %= self.get(cmd[2])
        elif cmd[0] == 'rcv':
            if not q[self.proc]:
                return False

            self.regs[cmd[1]] = q[self.proc].popleft()
        else:
            if self.get(cmd[1]) > 0:
                jmp = True
                self.pc += self.get(cmd[2])

        if not jmp:
            self.pc += 1

        return True

def main():
    prog = []
    for line in sys.stdin:
        cmd = tuple(line.strip().split())
        prog.append(cmd)

    p0, p1 = Prog(prog, 0), Prog(prog, 1)

    while True:
        if not p0.step() and not p1.step():
            break

    print(p1.sent)

main()
