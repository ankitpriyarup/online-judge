n = int(input())
ans = 0.0
for _ in range(n):
    a, b = map(float, input().split())
    ans += a * b
print(ans)
