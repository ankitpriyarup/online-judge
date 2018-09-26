n = int(input())
a = list(map(int, input().split()))
h = 0
ans = 0
store = 0
for x in a:
    needed = max(0, x - h)
    if needed > store:
        diff = needed - store
        ans += diff
        store += diff
    store -= x - h
    h = x

print(ans)
