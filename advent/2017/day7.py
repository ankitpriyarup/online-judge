from collections import *
import itertools
import random
import sys

def dfs(children, weights, root):
    exp = None
    s = weights[root]
    for child in children[root]:
        w = dfs(children, weights, child)
        s += w
        if exp is None:
            exp = w
        elif exp != w:
            print('expected child', child, 'to have weight', exp, 'has weight', w)
            print(w - weights[child])

    return s

def main():
    words = []
    bad = set()
    weights = {}
    children = defaultdict(list)
    for line in sys.stdin:
        line = line.strip().split()
        words.append(line[0])
        weights[line[0]] = int(line[1].strip('()'))

        if '->' in line:
            i = line.index('->')
            children[words[-1]] = [c.strip(',') for c in line[i + 1:]]
            bad |= set(children[words[-1]])

    for word in words:
        if word not in bad:
            root = word

    dfs(children, weights, root)


main()
