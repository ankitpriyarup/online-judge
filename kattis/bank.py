import heapq

n, t = map(int, input().split())
f = [[] for _ in range(t)]
for _ in range(n):
    c, e = map(int, input().split())
    f[e].append(c)

ans = 0
heap = []
for e in range(t - 1, -1, -1):
    for c in f[e]:
        heapq.heappush(heap, -c)
    if heap:
        ans -= heapq.heappop(heap)

print(ans)
