n, m = map(int, input().split())
xs = list(map(int, input().split()))
ts = list(map(int, input().split()))

humans = []
taxis = []
for x, t in zip(xs, ts):
    if t == 0:
        humans.append(x)
    else:
        taxis.append(x)

ans = [0 for _ in taxis]

for x in humans:
    lo = 0
    hi = len(taxis) - 1
    if taxis[lo] > x:
        ans[0] += 1
        continue
    while lo + 1 < hi:
        mid = (lo + hi) >> 1
        if taxis[mid] <= x:
            lo = mid
        else:
            hi = mid
    if x - taxis[lo] <= taxis[hi] - x:
        ans[lo] += 1
    else:
        ans[hi] += 1

print(' '.join(str(x) for x in ans))
