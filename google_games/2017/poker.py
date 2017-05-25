from itertools import product, combinations, combinations_with_replacement
from collections import Counter

score = 0
for spades in combinations(range(1, 14), 4):
    for heart in range(1, 14):
        s = sum(spades) + heart
        if 12 <= s <= 26 or 46 <= s <= 59:
            score += 1


print('asdfiasd', score)
