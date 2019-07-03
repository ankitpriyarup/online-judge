n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(1, n - 1):
    j = max(0, i - 1)
    k = min(n - 1, i + 1)
    b = a[j:k+1]
    b.sort()
    ans += b[1] == a[i]

print(ans)
