a = list(map(int, input().split()))
s = sum(a)
if s > 0 and s % 5 == 0:
    print(s // 5)
else:
    print(-1)
