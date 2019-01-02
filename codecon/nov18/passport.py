n = int(input())
m = int(input())
gs = [int(input()) for _ in range(m)]
times = [0 for _ in range(n)]
groups_hit = [0 for _ in range(n)]
for g in gs:
    # find the earliest person
    best = 0
    for i in range(n):
        if times[i] < times[best]:
            best = i

    times[best] += g
    groups_hit[best] += 1
    if groups_hit[best] >= 10 and groups_hit[best] % 10 == 1:
        times[best] += 5
    print('Group size', g, 'assigned', best, 'will now be free at time', times[best])

print(' '.join(str(x) for x in groups_hit))
