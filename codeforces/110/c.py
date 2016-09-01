n = int(input())

best_l = 1e9
best_y = 1e9

for x in range(n // 4 + 5):
    if n - 4 * x < 0 or (n - 4 * x) % 7 != 0:
        continue
    y = (n - 4 * x) // 7
    l = x + y
    if l < best_l or (l == best_l and y < best_y):
        best_l, best_y = l, y

if best_l == 1e9:
    print(-1)
else:
    arr = ['4'] * (best_l - best_y)
    arr += ['7'] * (best_y)
    print(''.join(arr))
