n = int(input())
x = float(input())
tot = 0.0
for _ in range(n):
    cur = x + sum(map(float, input().split()[1:]))
    tot += cur

avg = tot / n

print(avg)
