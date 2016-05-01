from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    graph = defaultdict(list)
    total = 1
    for _ in range(n):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
        total = max(total, x, y)

    q = [1]
    seen = set()
    ans = 0
    while q != []:
        cur = q[0]
        q = q[1:]
        if cur in seen:
            continue
        seen.add(cur)
        ans += len(graph[cur])
        q += graph[cur]

    if ans // 2 == total - 1:
        print("DEAD")
    else:
        print("SURVIVE")
