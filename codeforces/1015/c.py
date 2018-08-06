n, m = map(int, input().split())
deltas = []
tot = 0
for i in range(n):
    a, b = map(int, input().split())
    tot += a
    deltas.append(a - b)

deltas.sort()
ans = 0
while deltas and tot > m:
    tot -= deltas.pop()
    ans += 1

if tot > m:
    print(-1)
else:
    print(ans)
