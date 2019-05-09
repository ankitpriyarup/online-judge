n = int(input())
a = [1]
d = 1
for x in range(n - 1, 0, -1):
    a.append(a[-1] + d * x)
    d = -d

print(*a)
