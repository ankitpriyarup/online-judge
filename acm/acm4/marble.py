def dfs(x, cost, ends):
    if len(ends) == 0:
        return cost[x]

    maxx = 0
    for e in ends[x]:
        maxx = max(maxx, dfs(e, cost, ends))

    return cost[x] + maxx

R = int(raw_input())
for case_num in xrange(R):
    N = int(raw_input())
    cost = {}
    ends = {}
    for i in xrange(N):
        data = map(int, raw_input().split())
        cost[i] = data[0]
        ends[i] = data[1:]

    print dfs(0, cost, ends)
