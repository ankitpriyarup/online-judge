from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def f_r(f):
    def inner(before, a, b, c):
        state = list(before)
        state[c] = f(state[a], state[b])
        return tuple(state)

    return inner

def f_i(f):
    def inner(before, a, b, c):
        state = list(before)
        state[c] = f(state[a], b)
        return tuple(state)

    return inner

def setr(before, a, b, c):
    state = list(before)
    state[c] = state[a]
    return tuple(state)

def seti(before, a, b, c):
    state = list(before)
    state[c] = a
    return tuple(state)

def my_cmp(f, a_is_imm, b_is_imm):
    def inner(before, a, b, c):
        state = list(before)
        a_v = a if a_is_imm else state[a]
        b_v = b if b_is_imm else state[b]
        state[c] = 1 if f(a_v, b_v) else 0
        return tuple(state)

    return inner

ops = dict([
    ('addr', f_r(lambda x, y: x + y)),
    ('addi', f_i(lambda x, y: x + y)),
    ('mulr', f_r(lambda x, y: x * y)),
    ('muli', f_i(lambda x, y: x * y)),
    ('banr', f_r(lambda x, y: x & y)),
    ('bani', f_i(lambda x, y: x & y)),
    ('borr', f_r(lambda x, y: x | y)),
    ('bori', f_i(lambda x, y: x | y)),
    ('setr', setr),
    ('seti', seti),
    ('gtir', my_cmp(lambda x, y: x > y, True, False)),
    ('gtri', my_cmp(lambda x, y: x > y, False, True)),
    ('gtrr', my_cmp(lambda x, y: x > y, False, False)),
    ('eqir', my_cmp(lambda x, y: x == y, True, False)),
    ('eqri', my_cmp(lambda x, y: x == y, False, True)),
    ('eqrr', my_cmp(lambda x, y: x == y, False, False)),
])

def main():
    lines = [line.strip() for line in sys.stdin]
    instrs = [line.split() for line in lines[1:]]
    ip_reg = int(lines[0].split()[1])
    regs = [0 for _ in range(6)]
    regs[0] = 1

    ip = 0
    tot = 0
    while tot < 100 and ip < len(instrs):
        regs[ip_reg] = ip
        op, a, b, c = instrs[ip]
        a, b, c = map(int, [a, b, c])

        out = 'ip={} {} {} {} {} {}'.format(ip, regs, op, a, b, c)

        regs = ops[op](regs, a, b, c)

        out += ' {}'.format(list(regs))
        print(out)

        regs = list(regs)
        ip = regs[ip_reg] + 1
        tot += 1

    print(regs)
    print(tot)

main()
