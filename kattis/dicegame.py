from fractions import Fraction
dices = [list(map(int, input().split())) for _ in range(2)]

odds = [[0 for _ in range(201)] for _ in range(2)]
for p in range(2):
    den = (dices[p][1] + 1 - dices[p][0]) * (dices[p][3] + 1 - dices[p][2])
    for x in range(dices[p][0], dices[p][1] + 1):
        for y in range(dices[p][2], dices[p][3] + 1):
            odds[p][x + y] += Fraction(1, den)

p0_win = 0
p1_win = 0
for i in range(201):
    for j in range(i):
        p0_win += odds[0][i] * odds[1][j]
        p1_win += odds[1][i] * odds[0][j]

if p0_win == p1_win:
    print('Tie')
elif p0_win > p1_win:
    print('Gunnar')
else:
    print('Emma')
