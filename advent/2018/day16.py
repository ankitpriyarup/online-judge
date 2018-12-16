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

ops = [
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
]

def main():
    lines = [line.strip() for line in sys.stdin]
    names = frozenset(name for name, _ in ops)
    choices = [names for _  in range(16)]

    for i in range(0, len(lines), 4):
        if not lines[i].startswith('Before'):
            break
        before = eval(lines[i][lines[i].index('['):])
        op, a, b, c = map(int, lines[i + 1].split())
        after = eval(lines[i + 2][lines[i + 2].index('['):])
        valid_set = set()
        for name, action in ops:
            if action(before, a, b, c) == tuple(after):
                valid_set.add(name)

        choices[op] &= frozenset(valid_set)

    ass = ['' for _ in range(16)]
    while True:
        k, v = -1, -1
        for i in range(16):
            if len(choices[i]) == 1:
                k, v = i, list(choices[i])[0]
                break

        if k == -1:
            break
        ass[k] = v
        for i in range(16):
            if v in choices[i]:
                choices[i] = choices[i] - frozenset([v])

    print(ass)

    for i in range(0, len(lines), 4):
        if lines[i].startswith('Before'):
            continue
        start = i
        break

    state = (0, 0, 0, 0)
    for line in lines[start:]:
        op, a, b, c = map(int, line.split())
        name = ass[op]
        for op_name, f in ops:
            if op_name == name:
                state = f(state, a, b, c)
                break

    print(state)

main()
