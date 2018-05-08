def leq(a, x):
    return sum(y <= x for y in a)

n, k = map(int, input().split())
a = [int(x) for x in input().split()]
a.sort()
if k == 0:
    ans = a[0] - 1
else:
    ans = a[k - 1]

if ans <= 0 or leq(a, ans) != k:
    print(-1)
else:
    print(ans)

