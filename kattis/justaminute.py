n = int(input())
totm, tots = 0, 0
for _ in range(n):
    m, s = map(int, input().split())
    totm += m
    tots += s

totm *= 60
if totm >= tots:
    print('measurement error')
else:
    print('{:.10f}'.format(tots / totm))
