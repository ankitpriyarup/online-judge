n, m = map(int, input().split())
a = [0 for _ in range(n)]
for x in map(int, input().split()):
    a[x - 1] += 1

print(min(a))
