n = int(input())
a = set(int(input()) for _ in range(n))
m = max(a)
res = [x for x in range(1, m + 1) if x not in a]
if res:
    res.sort()
    for x in res:
        print(x)
else:
    print('good job')
