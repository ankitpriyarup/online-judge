from collections import *
from functools import reduce
import itertools
import random
import sys

def main():
    graph = defaultdict(list)
    for line in sys.stdin:
        words = line.strip().split()
        a = int(words[0])
        bs = map(lambda x: int(x.strip(',')), words[2:])
        for b in bs:
            graph[a].append(b)
            graph[b].append(a)

    vis = set()
    ans = 0
    for i in range(2000):
        if i in vis:
            continue
        ans +=1
        q = [i]
        while q:
            a = q.pop()
            for b in graph[a]:
                if b not in vis:
                    vis.add(b)
                    q.append(b)

    print(ans)


main()
