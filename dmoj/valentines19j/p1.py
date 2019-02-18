n = int(input())
ranks = ['Newbie', 'Amateur', 'Expert', 'Candidate Master', 'Master', 'Grandmaster', 'Target', 'Rainbow Master']
bars = [1000, 1200, 1500, 1800, 2200, 3000, 4000]
for _ in range(n):
    x = int(input())
    p = 0
    while p < len(bars) and x >= bars[p]:
        p += 1
    print(ranks[p])
