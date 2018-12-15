from collections import deque
import sys

CAP = 303
dist = [[float('inf') for _ in range(CAP)] for _ in range(CAP)]
dist[0][0] = 0
dq = deque([(0, 0)])
while dq:
    h, t = dq.popleft()
    # move one is useless, kill a head, get a head
    # move two, kill a tail, get two tails.
    if t >= 1:
        if dist[h][t] + 1 < dist[h][t - 1]:
            dist[h][t - 1] = dist[h][t] + 1
            dq.append((h, t - 1))
    # move three, kill two heads, nothing
    if h + 2 < CAP:
        if dist[h][t] + 1 < dist[h + 2][t]:
            dist[h + 2][t] = dist[h][t] + 1
            dq.append((h + 2, t))
    # move four, kill two tails, gain a head
    if h >= 1 and t + 2 < CAP:
        if dist[h][t] + 1 < dist[h - 1][t + 2]:
            dist[h - 1][t + 2] = dist[h][t] + 1
            dq.append((h - 1, t + 2))

for line in sys.stdin:
    h, t = map(int, line.strip().split())
    if h == 0 and t == 0:
        break
    print(-1 if dist[h][t] == float('inf') else dist[h][t])
