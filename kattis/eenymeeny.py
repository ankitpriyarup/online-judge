m = len(input().split())
n = int(input())
names = [input() for _ in range(n)]
teams = [[], []]
cur = 0
team = 0

m -= 1
while names:
    idx = (cur + m) % len(names)
    teams[team].append(names[idx])

    names = names[:idx] + names[idx + 1:]
    team = 1 - team
    cur = idx

for team in teams:
    print(len(team))
    for name in team:
        print(name)

