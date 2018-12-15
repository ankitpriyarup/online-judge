from collections import *
import itertools
import random
import sys

sys.setrecursionlimit(1000000)

def evolve(pot_inds, transitions):
    interesting_inds = set()
    for x in pot_inds:
        for d in range(-2, 3):
            interesting_inds.add(x + d)

    new_inds = set()
    for x in interesting_inds:
        context = ''.join('#' if x + d in pot_inds else '.' for d in range(-2, 3))
        if context in transitions:
            new_inds.add(x)

    return new_inds

def main():
    lines = [line.strip() for line in sys.stdin]
    init_state = lines[0]
    lines = lines[1:]
    transitions = [tuple(line.split(' => ')) for line in lines]
    transitions = dict((k, v) for k, v in transitions if v == '#')
    pot_inds = set(i for i, c in enumerate(init_state) if c == '#')

    ans = [x - 10000 + 50000000000 for x in [9947, 9955, 9966, 9971, 9976, 9981, 9986, 9994, 9999, 10004, 10009, 10017, 10024, 10029, 10035, 10040, 10045, 10053, 10058, 10063, 10072, 10079, 10084, 10089, 10094, 10099]]
    print(sum(ans))
    return

    for x in range(50000000000):
        if x > 0 and x % 10000 == 0:
            print(x, len(pot_inds))
            print(sorted(pot_inds))

        if x == 20000:
            break
        new_inds = evolve(pot_inds, transitions)
        if pot_inds == new_inds:
            break
        pot_inds = new_inds

    print(sum(pot_inds))

main()
