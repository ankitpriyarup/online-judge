n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans = n
j = 1
for i in range(n - 1):
    while j + 1 < n and a[i] == a[j]:
        j += 1
    if a[i] < a[j] and a[i] + k >= a[j]:
        ans -= 1

print(ans)
