n = int(input())
a = list(map(int, input().split()))

x = 0
y = n - 1
for i in range(n):
    if a[i] == 1:
        x = i
    if a[i] == n:
        y = i

old = abs(x - y)
if n == 2:
    print(1)
else:
    print(max(old, x, n - 1 - x, y, n - 1 - y))
