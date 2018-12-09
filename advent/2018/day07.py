from collections import *
import itertools
import heapq
import random
import sys

def main():
    lines = [line.strip() for line in sys.stdin]
    lines = [(line[5], line[36]) for line in lines]

    in_deg = defaultdict(int)
    status = {}
    done = set()
    graph = defaultdict(list)
    for a, b in lines:
        status[a] = False
        status[b] = False

        graph[a].append(b)

        in_deg[b] += 1

    free = 2
    block = 60
    t = 0
    workers = []
    while len(done) != len(status) or workers:
        # process all finishing ones
        while workers and workers[0][0] <= t:
            _, c = heapq.heappop(workers)
            for v in graph[c]:
                in_deg[v] -= 1

            free += 1

        for k in range(26):
            c = chr(ord('A') + k)
            if c not in status.keys():
                continue

            if free > 0 and c not in done and in_deg[c] == 0:
                print('starting', c, 'at', t)
                done.add(c)
                heapq.heappush(workers, (t + k + block + 1, c))
                free -= 1

        t += 1

    print(t - 1)

main()
