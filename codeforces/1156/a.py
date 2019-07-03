n = int(input())
a = list(map(int, input().split()))
is_inf = False

for i in range(0, n - 1):
    if a[i] > 1 and a[i + 1] > 1:
        is_inf = True
        break

ans = 0
for i in range(n):
    if a[i] != 1:
        s = 1 if i in [0, n - 1] else 2
        ans += s * (a[i] + 1)

for i in range(1, n - 1):
    if a[i - 1] == 3 and a[i + 1] == 2:
        ans -= 1

if is_inf:
    print('Infinite')
else:
    print('Finite')
    print(ans)
