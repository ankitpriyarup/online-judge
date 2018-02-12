n = int(input())
a = []
for _ in range(n):
    row = list(map(int, input().split()))
    row.sort()
    a.append(row[n // 2])

a.sort()
print(a[n // 2])
