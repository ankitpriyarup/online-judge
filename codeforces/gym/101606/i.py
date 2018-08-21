n = int(raw_input())
arr = map(int, raw_input().split())
t = int(raw_input())

best = arr[0]
for x in arr:
    cur_waste = t % x
    if cur_waste < t % best:
        best = x

print(best)
