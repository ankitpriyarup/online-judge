import heapq
n, m = map(int, input().split())
a = map(int, input().split())
pq = []
for x in a:
    heapq.heappush(pq, x)

for _ in range(m):
    x = heapq.heappop(pq)
    print(x)
    heapq.heappush(pq, x + 1)

