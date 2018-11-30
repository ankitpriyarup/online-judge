victory = [(8, "Province"), (5, "Duchy"), (2, "Estate")]
coins = [(6, "Gold"), (3, "Silver"), (0, "Copper")]
g, s, c = map(int, input().split())

money = 3 * g + 2 * s + c
best_v = None
best_c = None
for cost, name in victory:
    if cost <= money:
        best_v = name
        break
for cost, name in coins:
    if cost <= money:
        best_c = name
        break

if best_v is None:
    print(best_c)
else:
    print(best_v, 'or', best_c)
