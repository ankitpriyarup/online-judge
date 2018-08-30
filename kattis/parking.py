a, b, c = map(int, input().split())
events = []
for _ in range(3):
    s, e = map(int, input().split())
    events.append((s, 1))
    events.append((e, -1))

costs = [0, a, b, c]
events.sort()
have = 0
last = 0
ans = 0
for t, d in events:
    td = t - last
    ans += td * have * costs[have]
    have += d
    last = t

print(ans)
