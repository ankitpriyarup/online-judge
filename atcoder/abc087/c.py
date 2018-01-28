n = int(input())
a = []
for _ in range(2):
    s = list(map(int, input().split()))
    a.append(s)

for i in range(1, n):
    a[0][i] += a[0][i - 1]

for i in range(n - 2, -1, -1):
    a[1][i] += a[1][i + 1]

ans = max([a[0][i] + a[1][i] for i in range(n)])
print(ans)
