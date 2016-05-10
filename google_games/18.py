import itertools
you = [(5, 6), (4, 6), (1, 4), (5, 2), (3, 3), (4, 4), (9, 12)]
him = [(8, 6), (2, 4), (5, 10), (6, 6), (4, 11), (3, 7), (2, 5)]

#7 copies of numbers from 0 to 7
#7 means dont attack

a = [list(range(0, 8))] * 7
ans = (0, 0)

for p in itertools.product(*a):
    me = list(map(list, you[:]))
    his = list(map(list, him[:]))
    for i in range(7):
        # minion i attacks p[i]
        if p[i] == 7:
            continue

        his[p[i]][1] -= me[i][0]
        me[i][1] -= his[p[i]][0]

    destroyed = sum([1 if his[x][1] <= 0 else 0 for x in range(7)])
    health = sum([max(0, x[1]) for x in me])

    ans = max(ans, (destroyed, health))

print(ans)
    

"""
ans = (0, sum([x[1] for x in you]))
for p in itertools.permutations(range(len(you))):
    for k in range(1, len(p) + 1):
        for sub in itertools.combinations(enumerate(p), k):
            destroyed = 0
            health = 0
            for a, b in sub:
                # you[a] attacks b
                mine = you[a]
                bad = him[b]

                healthleft = mine[1] - bad[0]
                health += max(0, healthleft)

                if mine[0] >= bad[1]:
                    destroyed += 1

            cur = (destroyed, health)
            if cur > ans:
                print(sub)
                ans = cur

print(ans)
"""
