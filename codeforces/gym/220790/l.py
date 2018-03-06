n = int(input())
skills = ['strong', 'skilled', 'experienced', 'chivalrous', 'sneaky']
ppl = []
for _ in range(n):
    name, skill = input().split()
    skill = skills.index(skill.lower())
    ppl.append(([name], skill))

wins = [[False, True, False, False, True], 
        [False, False, True, False, True],
        [True, False, False, True, False],
        [True, True, False, False, False],
        [False, False, True, True, False]]

while len(ppl) > 1:
    winners = []
    for i in range(0, len(ppl), 2):
        if ppl[i][1] == ppl[i + 1][1]:
            winners.append((ppl[i][0] + ppl[i + 1][0], ppl[i][1]))
        elif wins[ppl[i][1]][ppl[i + 1][1]]:
            winners.append(ppl[i])
        else:
            winners.append(ppl[i + 1])

    ppl = winners

if len(ppl[0][0]) > 1:
    print('Chaos is a ladder')
else:
    print(ppl[0][0][0])
