from math import ceil
from itertools import product, combinations

# cost, damage, armor
weapons = [ (8, 4, 0),
            (10, 5, 0),
            (25, 6, 0),
            (40, 7, 0),
            (74, 8, 0) ]

armors = [  (0, 0, 0),
           (13, 0, 1),
           (31, 0, 2),
           (53, 0, 3),
           (75, 0, 4),
           (102, 0, 5) ]

rings = [ (25, 1, 0),
          (50, 2, 0),
          (100, 3, 0),
          (20, 0, 1),
          (40, 0, 2),
          (80, 0, 3) ]

def sim(damage, armor, health):
    monster_health = 104
    monster_dmg = max(8 - armor, 1)
    monster_armor = 1

    damage = max(damage - monster_armor, 1)

    # simulate a turn
    while health > 0:
        monster_health -= damage
        if monster_health <= 0:
            return True
        health -= monster_dmg
        if health <= 0:
            return False

ans = 0
rings = [ ((0, 0, 0), (0, 0, 0)) ] + map(lambda x: (x, (0, 0, 0)), rings) + map(lambda x: ((0, 0, 0), x), rings) + list(combinations(rings, 2))
for (a, b, (c, d)) in product(weapons, armors, rings):
    cost = a[0] + b[0] + c[0] + d[0]
    damage = a[1] + b[1] + c[1] + d[1]
    armor = a[2] + b[2] + c[2] + d[2]

    if not sim(damage, armor, 100):
        ans = max(ans, cost)
        if ans == cost:
            print a, b, c, d

print ans
