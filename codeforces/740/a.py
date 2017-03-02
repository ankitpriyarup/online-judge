n, a, b, c = map(int, input().split())

ans = float('inf')
for i in range(12):
    for j in range(12):
        for k in range(12):
            if (n + i + 2 * j + 3 * k) % 4 != 0:
                continue

            cost = (a * i) + (b * j) + (c * k)
            ans = min(ans, cost)

print(ans)
