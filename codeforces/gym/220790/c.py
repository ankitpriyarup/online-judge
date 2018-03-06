n, r = map(int, input().split())
debt = 0
for _ in range(n):
    a, b = map(int, input().split())
    cur_debt = a
    for _ in range(b):
        cur_debt += (cur_debt / 100.0) * r

    debt += cur_debt

print(debt)
