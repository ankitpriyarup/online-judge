from collections import *
import itertools
import random
import sys

ans = 0

def read_node(stream, p):
    num_children = stream[p]
    num_data = stream[p + 1]
    p += 2
    children, data = [], []
    for _ in range(num_children):
        child, p = read_node(stream, p)
        children.append(child)

    global ans
    for _ in range(num_data):
        data.append(stream[p])
        ans += data[-1]
        p += 1

    value = 0
    if not children:
        value = sum(data)
    else:
        for x in data:
            if 0 <= x - 1 < num_children:
                value += children[x - 1][2]


    return (children, data, value), p


def main():
    stream = list(map(int, input().split()))
    root, p = read_node(stream, 0)
    assert(p == len(stream))

    print(root[2])

main()
