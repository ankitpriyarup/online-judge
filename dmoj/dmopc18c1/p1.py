n = int(input())
a = [int(x) for x in input().split()]
lb = -1
ub = int(1e9 + 7)
for i in range(1, n):
    if a[i] == 0:
        lb = max(lb, a[i - 1])
for i in range(n - 2, -1, -1):
    if a[i] == 0:
        ub = min(ub, a[i + 1])

b = []
for x in a:
    if x == 0:
        b.append(lb)
    else:
        b.append(x)
is_sort = all(b[i - 1] <= b[i] for i in range(1, n))
print('YES' if is_sort and lb <= ub else 'NO')
