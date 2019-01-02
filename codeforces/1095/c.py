import heapq

n, k = map(int, input().split())
pq = []
for i in range(32):
    if (n & (1 << i)) > 0:
        heapq.heappush(pq, -(1 << i))

while len(pq) < k:
    v = heapq.heappop(pq)
    v = -v
    if v == 1:
        pq = []
        break
    heapq.heappush(pq, -(v >> 1))
    heapq.heappush(pq, -(v >> 1))

if len(pq) != k:
    print('NO')
else:
    print('YES')
    print(' '.join(str(-x) for x in pq))
