n, s = map(int, input().split())
t = list(map(int, input().split()))
t.sort()
ms = t[-1] * s
ans = (ms + 999) // 1000
print(ans)
