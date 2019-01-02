from collections import defaultdict
import itertools
import heapq

num_quarters = int(input().split()[1])

monies = defaultdict(lambda: 100)
fuels = defaultdict(list)
resources = defaultdict(lambda: defaultdict(int))
factories = defaultdict(list)

for _ in range(num_quarters):
    lines = int(input().split()[2])
    for _ in range(lines):
        line = input().split()
        if line[0] == 'BUY_PLANT':
            company, kind, req, cost, income = line[1:]
            req, cost, income = map(int, [req, cost, income])
            monies[company] -= cost
            factories[company].append((kind, req, income))
        elif line[0] == 'FUEL':
            kind, amt, cost = line[1:]
            amt, cost = map(int, (amt, cost))
            for _ in range(amt):
                heapq.heappush(fuels[kind], cost)
        elif line[0] == 'BUY_FUEL':
            company, kind, amt = line[1:]
            amt = int(amt)
            for _ in range(amt):
                monies[company] -= heapq.heappop(fuels[kind])
                resources[company][kind] += 1

    for company in factories.keys():
        best_set = []
        best_pot = 0

        for k in range(1, len(factories[company]) + 1):
            for subset in itertools.combinations(factories[company], k):
                needed = defaultdict(int)
                pot = 0
                for kind, req, income in subset:
                    needed[kind] += req
                    pot += income
                if pot > best_pot and all(needed[kind] <= resources[company][kind] for kind in needed.keys()):
                    best_pot = pot
                    best_set = subset

        for kind, req, income in best_set:
            resources[company][kind] -= req
            monies[company] += income

ans = list(monies.items())
ans.sort()
for x in ans:
    print(*x)
