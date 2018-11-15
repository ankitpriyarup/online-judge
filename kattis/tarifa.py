x = int(input())
n = int(input())
ans = x
for _ in range(n):
    y = int(input())
    ans += x - y

print(ans)
