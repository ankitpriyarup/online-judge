n, m = map(int, input().split())
segs = []
for _ in range(n):
    l, r = map(int, input().split())
    segs.append((l, r))

ans = []
for x in range(1, m + 1):
    if not any(l <= x <= r for l, r in segs):
        ans.append(str(x))

print(len(ans))
if ans:
    print(' '.join(ans))
