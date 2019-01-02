c, n = map(int, input().split())
log = [(c, set())]
opts = set()
for _ in range(n):
    line = input().split()
    num_candies = int(line[0])
    log.append((num_candies, line[1:]))
    opts |= set(log[-1][1])

culprits = set(opts)

for i in range(1, n + 1):
    if log[i][0] == log[i - 1][0]:
        continue
    culprits &= set(log[i][1])

ans = []
opts = opts | set('bad_parent_test')
for c in culprits:
    for parent in opts:
        if c == parent:
            continue

        # print('Trying', c, parent)
        works = True
        for i in range(1, n + 1):
            if log[i][0] == log[i - 1][0] and c in log[i][1] and parent not in log[i][1]:
                # print('Fail, candy not taken, no parent')
                works = False
                break
            if log[i][0] != log[i - 1][0] and c not in log[i][1]:
                # print('Fail, candy taken, no culprit')
                works = False
                break
            if log[i][0] != log[i - 1][0] and c in log[i][1] and parent in log[i][1]:
                # print('Fail, candy taken, culprit and parent')
                works = False
                break

        if works:
            ans.append((c, parent))

if len(ans) == 1:
    print(*ans[0])
elif len(set(x[0] for x in ans)) == 1:
    print(ans[0][0], 'UNKNOWN')
else:
    print('UNKNOWN')
