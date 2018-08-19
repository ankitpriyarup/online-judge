def div(x):
    ans = 0
    for i in range(1, x + 1):
        if x % i == 0:
            ans += 1
    return ans
n = int(input())
ans = 0
for x in range(1, n + 1, 2):
    if div(x) == 8:
        ans += 1
print(ans)
