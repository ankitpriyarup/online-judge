from collections import *
import itertools
import math
import sys
from heapq import *

def main():
    r = int(input())
    graph = defaultdict(list)
    for _ in range(r):
        line = input().split()
        o, d, dur, n = line[:4]
        dur = int(dur)
        n = int(n)
        times = [int(x) for x in line[4:]]
        for t in times:
            for buf in range(0, 10000, 1440):
                graph[o].append((d, dur, t + buf))

    src, sink, dep = input().split()
    dep = int(dep)

    dist = defaultdict(int)
    dist[src] = dep
    pq = []
    heappush(pq, (dep, src))

    while pq:
        t, pos = heappop(pq)
        if dist[pos] < t:
            continue

        if pos == sink:
            print(t - dep)
            return
        for v, dur, tt in graph[pos]:
            if tt < t:
                continue
            if v not in dist or tt + dur < dist[v]:
                heappush(pq, (tt + dur, v))
                dist[v] = tt + dur

    print('IMPOSSIBLE')

main()
